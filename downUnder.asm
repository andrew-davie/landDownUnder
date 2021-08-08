; DownUnder
; (c) 2021 Andrew Davie

; REMEMBER cannot use lda # as this is overloaded for datastream access!!
; use ldx # or ldy # instead

        PROCESSOR 6502
        include "vcs.h"       
        include "macro.h"
        include "cdfj.h"

    MAC FETCH ; stream, destination
    lda #{1}
    sta {2}
    ENDM

    MAC ldx
    ENDM

; Symbols prefixed with _ are exported to 'main/defines_from_dasm_for_c.h'
; This is done via 'awk' in the makefile.


; which ARM function to run
_FN_INIT        = 0 ; Initialize()
_FN_GAME_OS     = 1 ; GameOverscan()
_FN_GAME_VB     = 2 ; GameVerticalBlank()
_FN_MENU_OS     = 3 ; MenuOverScan()
_FN_MENU_VB     = 4 ; MenuVerticalBlank()
_FN_SPLASH_OS   = 5 ; SplashOverScan()
_FN_SPLASH_VB   = 6 ; SplashVerticalBlank()
_FN_GAME_IDLE   = 7 ; idle loop

; datastream usage for Splash Screen
_DS_SPLASH_P0L  = DS0DATA
_DS_SPLASH_P1L  = DS1DATA
_DS_SPLASH_P0R  = DS2DATA
_DS_SPLASH_P1R  = DS3DATA

; datastream usage for Menu
;_DS_MENU_GRAPHICS    = DS0DATA
;_DS_MENU_CONTROL     = DS1DATA
;_DS_MENU_COLORS      = DS2DATA

; datastream usage for Game Kernel
_DS_PF0_LEFT    = DS4DATA
_DS_PF1_LEFT    = DS5DATA
_DS_PF2_LEFT    = DS6DATA
_DS_PF0_RIGHT   = DS7DATA
_DS_PF1_RIGHT   = DS8DATA
_DS_PF2_RIGHT   = DS9DATA

_DS_COLUPF      = DS10DATA
_DS_COLUBK      = DS13DATA
_DS_COLUP0      = DS0DATA
_DS_COLUP1      = DS1DATA

_DS_AUDV0       = DS14DATA
_DS_AUDC0       = DS15DATA
_DS_AUDF0       = DS16DATA


_DS_GRP0a = DS11DATA
_DS_GRP1a = DS12DATA
;_DS_GRP0b = DS13DATA
;_DS_GRP1b = DS14DATA
;_DS_GRP0c = DS15DATA
;_DS_GRP1c = DS16DATA
    
; timer values
VB_TIM64T = 50;46; //7; //7
OS_TIM64T = 21; 41; //33 ;-3

; color values
_BLACK           = $00
_WHITE           = $0E
_GREY            = $00
_YELLOW          = $10
_ORANGE          = $20
_BROWN           = $30
_RED             = $40
_PURPLE          = $50
_VIOLET          = $60
_INDIGO          = $70
_BLUE            = $80
_BLUE2           = $90
_TURQUOISE       = $A0
_CYAN            = $B0
_GREEN           = $C0
_YELLOW_GREEN    = $D0
_OCHRE_GREEN     = $E0
_OCHRE           = $F0

;_HAIR            = $F4
;_FACE            = $4C

; controls spacing in main menu

_ARENA_SCANLINES    = 198   ; number of scanlines for the arena
ARENA_BUFFER_SIZE   = 198    ; PF buffer size for largest arena

;===============================================================================
; Define custom Macros
;----------------------------------------
; POSITION_OBJECT is defined as a macro because it appears at the same position
; in both banks of 6507 code.
;
; CHECK_ARENA_BUFFER_SIZE is used to make sure the playfield buffers are large
; enough for the graphics. 
;===============================================================================
        MAC POSITION_OBJECT
        ; sets X position of any object.  X holds which object, A holds position
PosObject:              ; A holds X value
        sec             ; 2  
        sta WSYNC       ; X holds object, 0=P0, 1=P1, 2=M0, 3=M1, 4=Ball
DivideLoop:
        sbc #15         ; 2  
        bcs DivideLoop  ; 2  4
        eor #7          ; 2  6
        asl             ; 2  8
        asl             ; 2 10
        asl             ; 2 12
        asl             ; 2 14
        sta.wx HMP0,X   ; 5 19
        sta RESP0,X     ; 4 23 <- set object position
SLEEP12: rts            ; 6 29
        ENDM
        
            
        MAC CHECK_ARENA_BUFFER_SIZE
        ; trigger a compile time error if the arena buffer need to be increased
            IF {1} > ARENA_BUFFER_SIZE
                echo "Increase ARENA_BUFFER_SIZE to",[{1}]d
                err
            ENDIF
        ENDM
        
        
;===============================================================================
; Define Zero Page RAM Usage
;----------------------------------------
;   ZP RAM variables can only be seen by the 6507 CPU
;   Likewise C variables can only be seen by the ARM CPU
;===============================================================================

        SEG.U VARS
        ORG $80       
        
Mode:           ds 1    ; $00 = splash, $01 = menu, $80 = game
                        ; these values allow for easy testing of Mode:
                        ;   LDA Mode
                        ;   BMI GAME_ROUTINE
                        ;   BNE MENU_ROUTINE
                        ;   BEQ SPLASH_routine 
LoopCounter:    ds 1      
TimeLeftOS:     ds 1
TimeLeftVB:     ds 1
Temp            ds 1

        echo "----",($00FE - *) , "bytes of RAM left (space reserved for 2 byte stack)"
             
        

;===============================================================================
; Define Start of Cartridge
;----------------------------------------
;   CDFJ cartridges must start with the Harmony/Melody driver.  The driver is
;   the ARM code that emulates the CDFJ coprocessor.
;===============================================================================

                    SEG CODE    
                    ORG 0
    
                    incbin "cdfdriver20190317.bin"

        
        
;===============================================================================
; ARM user code
; Banks 0 thru 4
;----------------------------------------
;   The ARM code starts at $0800 and grows into bank 0+
;===============================================================================

                    ORG $0800
        
    ; include the custom ARM code.

                    incbin "main/bin/armcode.bin"

        
        
        
;===============================================================================
; ARM Indirect Data
;----------------------------------------
;   Data that the C code indirectly accesses can be stored immediately after the
;   custom ARM code.
;===============================================================================

        echo "----",($7000 - *) , "bytes of ARM and Moveable Data space left"
 
        
        
;===============================================================================
; ARM Direct Data
;----------------------------------------
;   I find it easier, and more space efficient, to store some of the data the
;   C code needs to access in the 6507 code instead of the C code.  Because the
;   build process is:
;
;       1) assemble 6507 code to create defines_from_dasm_for_c.h
;       2) compile C code to create ARM routines
;       3) assemble 6507 to create final ROM
;
;   the ARM code could change size between steps 1 and 3, which would shift data 
;   that immediately comes after it. So the data that C directly accesses needs
;   to be after an ORG to prevent it from moving.
;
;   The _IMAGE_GRAPHICS, _IMAGE_COLORS, etc data tables are directly access by
;   the C code so must be in the Direct Data area. The data they point to is
;   indirectly accessed by the C code, so they can go in the Indirect Data area.
;   Note the labels for the tables are prefixed by _ so they'll end up in the
;   defines_from_dasm_for_c.h file, while the labels for the data the tables
;   point to are not prefixed by _
;===============================================================================
;        ORG $5F80
;        ORG $5FFF
;_ARENA_INCREMENTS:        
;        .byte 255 ; * Arena1_Height / _ARENA_SCANLINES
;        .byte 255 ;* Arena2_Height / _ARENA_SCANLINES
;        .byte 255 ;* Arena3_Height / _ARENA_SCANLINES
;        .byte 255 ;* Arena4_Height / _ARENA_SCANLINES      
        


    ; value used in this echo depends upon how many banks are used for 6507 code
    ;   $5000 if using banks 4, 5 & 6
    ;   $6000 if using banks 5 & 6
    ;   $7000 if using just bank 6
;    echo "----",[$6000 - *] , "bytes of ARM Direct Data left"   
        
;===============================================================================
; Bank 5 - 6507 code
;----------------------------------------
;   I normally allocate banks 0-5 for ARM code, and just use bank 6 for 6507
;   code, but in order to show an example of CDFJ bankswitching I am using bank
;   5 for the splash screen and menu routines.
;===============================================================================

;        ORG $6000
;        RORG $F000  

    ; this and SplashMenuVB in bank 6 are used to switch between the banks        
;SplashMenuOS:        
;        sta SELECTBANK6         ; switch to bank 6, then jmp SplashMenuOS_Code
;        jmp SplashMenuVB_Code
        
;        POSITION_OBJECT         ; this must occupy same address in both banks
        
        
        
;===============================================================================
; Two Color Graphic routine
;-------------------------------------------------------------------------------
; this works by using a "negative" image when drawing the sprites.
; The sprites are colored black while the background is the color
; that shows up as though it were the sprites.  The 2nd color is
; achieved by using the playfield and/or ball.
;
; The missiles (also black) and setting the screen & playfield to BLACK
; are used to hide the screen and playfield beyond the 48 pixel image.
;===============================================================================
;ShowTwoColorGraphic:
        
        
;SplashMenuVB_Code:      ; entry point from Bank 6
;        lda Mode        ; check which screen to show
;        bne MenuVB      ; Mode 1 = Menu
;        jmp SplashVB    ; Mode 0 = Splash
        
;MenuVB:
        ; players are already in position, just need to set size/copies & color
;        ldy #%11111111
;        sty GRP0
;        sty GRP1
;        ldy #%00100000  ; Ball Size = 4
;        sty CTRLPF      ; repeat playfield, ball width = 4  
;        ldy #_BLACK
;        sty COLUP0
;        sty COLUP1
;        ldy #%00010000;11 
;        sty ENAM0           ; missile on
;        sty ENAM1           ; missile on
;        sty ENABL           ; ball on
;        sty NUSIZ0          ; three copies close, missile x8
;        sty NUSIZ1          ; three copies close, missile x8
;        sty VDELP0          ; vertical delay on 
;        sty VDELP1          ; vertical delay on


;        ldx #0
;        stx COLUPF
;MenuVBwait:
;        sta WSYNC
;        bit TIMINT
;        bpl MenuVBwait
;        stx VBLANK              ; video output on
         
;MenuKernel:
       
;MenuDone:
;        sta WSYNC
;        stx ENAM0    ; X=0 after ShowTwoColorGraphic
;        stx ENAM1
;        stx ENABL
        
        
;ShowSpiceWareLogo:  
;SSWL1:
;SSWLskip1:                      ;   15 from branch just before SSWL1
;EndShowSpiceWareLogo:                   
        
;MenuOS:
;        ldy #_FN_MENU_OS    ; going to run function MenuOverScan()
;        jmp SplashMenuOS


;SplashVB:
;SplashVBwait:
;SplashKernel:
;SplashOS:
;        ldy #_FN_SPLASH_OS      ; going to run function SplashOverScan()
;        jmp SplashMenuOS
        

;    echo ($FFE9-*), "(6507) bytes left in bank 6"

    ;include "48x128.asm"


;    echo ($FFE9-*), "AFTER 48x128 include, (6507) bytes left in bank 6"

;        ORG $6FEA
;        RORG $FFEA
;B5init:        
;        sta SELECTBANK6
;        jmp B5init      ; should never get here, but just in case
;        ds 12, 0        ; reserve space for CDFJ registers
;        .WORD B5init    ; while CDFJ will only power up in bank 5, an accidental
;        .WORD B5init    ; BRK instruction could occur, so gracefully handle it
        
        
        
;===============================================================================
; Bank 6 - 6507 code
;----------------------------------------
;   CDFJ will always start in bank 6 because banks 0-5 could contain ARM code
;===============================================================================

        ORG $7000
        RORG $F000
        
    ; this and SplashMenuOS in bank 5 are used to switch between the banks                
SplashMenuVB:        
        sta SELECTBANK5         ; switch to bank 5, then jmp SplashMenuVB_Code 
        jmp SplashMenuOS_Code      
        
        POSITION_OBJECT         ; this must occupy same address in both banks        
        
        ; CallArmCode is only called from bank 6. If we needed to also call it
        ; from bank 5 then we would set up a macro like POSITION_OBJECT

CallArmCode

    ; Y = function to run
    ;   _FN_GAME_OS     game overscan


                    ldx #<_DS_TO_ARM
                    stx DSPTR
                    ldx #>_DS_TO_ARM                ; NOTE: if _DS_TO_ARM = 0 we can leave out this LDX
                    stx DSPTR           
                    sty DSWRITE                     ; save in _RUN_FUNC, Y holds which function to call
                    ldx SWCHA                       ; read state of both joysticks
                    stx DSWRITE                     ; save in _SWCHA 
                    ldx SWCHB                       ; read state of console switches
                    stx DSWRITE                     ; save in _SWCHB
                    ldx INPT4                       ; read state of left joystick firebutton
                    stx DSWRITE                     ; save in _INPT4 
                    ldx INPT5                       ; read state of right joystick firebutton
                    stx DSWRITE                     ; save in _INPT5
                    ldx TimeLeftVB                  ; Time remaining in VB (only tracked for game screen)
                    stx DSWRITE                     ; save in _VB_TIME
                    ldx TimeLeftOS                  ; Time remaining in OS (only tracked for game screen)
                    stx DSWRITE                     ; save in _OS_TIME

                    ldx #$FF                        ; FF = Run ARM code w/out digital audio interrupts
                    stx CALLFN                      ; runs main() in the C code (6507 is $EA-locked)

                    FETCH DSCOMM, Mode              ; get the current game mode
                    rts        


safeTimerWait

    ; Now we wait for expiry of the timer.
    ; The code records the available time for display. This is the INTIM value at the start
    ; of the wait. This INTIM read clears the TIMINT flag, so we go through some convolutions
    ; to make it all work.


                    ldx #0
                    bit TIMINT
                    bmi .zeroTime                   ; already overtime!
                    lda INTIM
                    beq .zeroTime                   ; also time expired
                    bmi .zeroTime                   ; must have been just overtime and now counting down
                    tax
.xOSwait            sta WSYNC
                    bit TIMINT                      ; wait for the timer
                    bpl .xOSwait

.zeroTime           stx TimeLeftOS                  ; x holds the "how much time left"
                    rts


       
InitSystem:
; Console Detection Routine
;
; normally we'd use CLEAN_START, but to detect if console is 2600 or 7800
; we need to take a look at the ZP RAM values in $80, $D0, and $D1 before
; zeroing out RAM
;
;   if $D0 contains $2C and $D1 contains $A9 then
;       system = 7800           // game was loaded from Harmony menu on a 7800
;   else if both contain $00 then
;       system = ZP RAM $80     // game was flashed to Harmony/Melody so CDFJ
;                               // driver checked $D0 and $D1 for us and saved
;                               // results in $80
;   else
;       system = 2600           // game was loaded from Harmony menu on a 2600

        sei 
        cld
        
        ldy #0              ; assume system = 2600        
        ldx $d0
        beq .confirmFlashed ; if $00 then game might be flashed on Harmony/Melody
        cpx #$2c+2
        bne .is2600         ; if not $2C then loaded via Harmony Menu on 2600        
        ldx $d1
        cpx #$a9
        bne .is2600
        dey                 ; 7800: y=$FF
        bne .done           ; this will always branch
        
.confirmFlashed        
        ldx $d1
        bne .is2600         ; if not $00 then loaded via Harmony Menu on 2600
        ldy $80             ; else get the value saved by the CDFJ driver
        
.is2600                     ; 2600: y == 0
.done                       ; 7800: y != 0
; end of console detection routine, y contains results

                    ldx #0
                    txa
CLEAR_ZP            dex
                    txs
                    pha
                    bne CLEAR_ZP     ; SP=$FF, X = A = 0
        
        ; Fast Fetch mode must be turned on so we can read the datastreams
        ; Note: Fast Fetch mode overrides LDA #, so need to use LDX # or
        ;       LDY # if not reading a CDFJ register
        ldx #FASTON
        stx SETMODE
        
        ldx #<_DS_TO_ARM
        stx DSPTR
        ldx #>_DS_TO_ARM    ; NOTE: if _DS_TO_ARM = 0 we can leave out this LDX
        stx DSPTR
        ldx #_FN_INIT       ; going to run function Initialize()
        stx DSWRITE         ; save in _RUN_FUNC
        sty DSWRITE         ; save 2600/7800 value in _SWCHA 
        sty DSWRITE         ; save 2600/7800 value in _SWCHB
        sty DSWRITE         ; save 2600/7800 value in _INPT4 
        sty DSWRITE         ; save 2600/7800 value in _INPT5
        ldx #$FF            ; FF = Run ARM code w/out digital audio interrupts
        stx CALLFN          ; runs main() in the C code        

;        ldy #_FN_SPLASH_OS      ; going to run function SplashOverScan()
;        bne SplashMenuOS_Code



OverScan:

;    ldx #$C4
;    stx COLUBK


;        ldy #_FN_GAME_OS        ; going to run function GameOverscan()
SplashMenuOS_Code:    ; entry point from bank 5 & InitSystem with Y already set        
        sta WSYNC
        ldx #2
        stx VBLANK              ; video output off
        ldx #OS_TIM64T
        stx TIM64T              ; set timer for OS


                    ldy #_FN_GAME_OS

Again2              jsr CallArmCode                 ; draws the chessboard!

                    ldx TIMINT
                    bmi .ag2
                    ldy #_FN_GAME_IDLE
                    ldx INTIM
                    cpx #10
                    bcs Again2


;                ldx #$C2
;                stx COLUBK

                    jsr safeTimerWait

.ag2



VerticalSync:
        ldy #2
;    ldx #$46
;    stx COLUBK ;boo
        ldx #VB_TIM64T
        sty WSYNC


; --- start scanline 1 of Vertical Sync ---        
        sty VSYNC           ; 3  3  turn on Vertical Sync signal
        stx TIM64T          ; 4  7        
        sty WSYNC           ; 3 10/0
; --- start scanline 2 of Vertical Sync ---        
        ; use otherwise wasted time to zero out some TIA registers
        ldx #0              ; 2  2
        stx GRP0            ; 3  5
        stx GRP1            ; 3  8
        ;stx VDELP0          ; 3 11
        ;stx VDELP1          ; 3 14
        stx PF0             ; 3 17
        stx PF1             ; 3 20
        stx PF2             ; 3 23
        stx CTRLPF          ; 3 26
        stx WSYNC           ; 3 29/0
; --- start scanline 3 of Vertical Sync ---        
        ; use otherwise wasted time to figure out
        ; which ARM Vertical Blank routine to run
;        lda Mode            ; 3  3 $00 = splash, $01 = menu, $80 = game
;        bmi vbgame          ; 2  5  3  6 if taken
;        beq vbsplash        ; 2  7     |  3  8 if taken
;        ldy #_FN_MENU_VB    ; 2  9     |     |  run function MenuVerticalBlank()
;        .byte $0c           ; 4 13     |     |  NOP ABSOLUTE, skips over ldy #_FN_SPLASH_VB         
;vbsplash:                   ;    |     |     |
;        ldy #_FN_SPLASH_VB  ;    |     |  2 10  run function SplashVerticalBlank()
;        .byte $0c           ; 4 17     |  4 14  NOP ABSOLUTE, skips over ldy #_FN_GAME_VB
;vbgame:                     ;    |     |     |
;        ldy #_FN_GAME_VB    ;    |  2  8     |  run function GameVerticalBlank()
                            ;   17     8    14  17 cycles worse case scenerio
        stx WSYNC           ; end of VerticalSync scanline 3
        stx VSYNC           ; turn off Vertical Sync signal            
;        jsr CallArmCode
        
    IF 1
        ; ARM VB routines send back the initial positions of the 5 objects      
;vbSetInitialX:        
;        lda #DSCOMM         ; will get _BALL_X,  _M1_X,  _M0_X,  _P1_X,  and _P0_X
 
    lda #DSCOMM     ; discard _BALL_X
    lda #DSCOMM     ; and _M1_X
    lda #DSCOMM     ; and _M0_X
 
    ldx #1
    lda #DSCOMM     ; = _P1_X
    jsr PosObject

    dex
    lda #DSCOMM     ; = _P0_X
    jsr PosObject

;        jsr PosObject
;        inx
;        lda #DSCOMM         ; will get _BALL_X,  _M1_X,  _M0_X,  _P1_X,  and _P0_X
;        jsr PosObject
;        dex        
;        bpl vbSetInitialX
        sta WSYNC
        sta HMOVE


        lda #DSCOMM         ; ARENA COLOR
        sta COLUBK

        lda #_DS_AUDV0
        sta AUDV0
        lda #_DS_AUDC0
        sta AUDC0
        lda #_DS_AUDF0
        sta AUDF0

        lda #_DS_AUDV0
        sta AUDV1
        lda #_DS_AUDC0
        sta AUDC1
        lda #_DS_AUDF0
        sta AUDF1

        ; figure out which 6507 Vertical Blank routine to run
 ;       lda Mode            ; $00 = splash, $01 = menu, $80 = game
 ;       bmi GameVB
 ;       jmp SplashMenuVB
        
GameVB:        
    ENDIF


                    ldy #_FN_GAME_VB

Again1              jsr CallArmCode                 ; draws the chessboard!

                    ldy #_FN_GAME_IDLE

                    ldx TIMINT
                    bmi skipss
                    ldx INTIM
                    cpx #10
                    bcs Again1

                    jsr safeTimerWait

 
skipss
                    ldx #0
                    stx VBLANK              ; video output on
 ;                   stx PF0


;                    sta WSYNC
;                    sta WSYNC
                    ldx #%00000000
                    stx CTRLPF


;                    sta WSYNC
 
;                     jmp FASTJMP1



_NORMAL_KERNEL


    ; This is the entire display

;@3


                    lda #_DS_COLUBK
                    sta WSYNC
                    sta COLUBK

                    lda #_DS_COLUPF
                    sta COLUPF

                    lda #_DS_PF0_LEFT
                    sta PF0                         ; 5

                    lda #_DS_GRP0a
                    sta GRP0                        ; 5

                    lda #_DS_PF1_LEFT
                    sta PF1                         ; 5

                    lda #_DS_GRP1a
                    sta GRP1                        ; 5



                    lda #_DS_PF2_LEFT
                    sta PF2                         ; 5


        SLEEP 5

                    lda #_DS_PF0_RIGHT
                    sta PF0
                    lda #_DS_PF1_RIGHT
                    sta PF1                         ; 5
                    lda #_DS_PF2_RIGHT              ; 2
                    sta PF2                         ; 3 


        SLEEP 5
                    lda #_DS_COLUP0
                    sta COLUP0                      ; 3 @8
                    lda #_DS_COLUP1
                    sta COLUP1


                    jmp FASTJMP1                    ; 3

;@3--> start of line again :)


_EXIT_KERNEL        ldx #0                
                    stx GRP0
                    stx GRP1
                    stx PF0
                    stx PF1
                    stx PF2                    
                    jmp OverScan
        

    echo *
    echo ($FFEC-*), "(6507) bytes left in bank 7"

    ORG $7FED
    RORG $FFED
                    jmp InitSystem
    ds 12, 0                                        ; reserve space for CDFJ registers
    .WORD InitSystem
    .WORD InitSystem
        
;===============================================================================
; Display Data
;----------------------------------------
;   4K of RAM shared between the 6507 and ARM.
;
;   NOTE: anything prefixed with _ ends up in main/defines_from_dasm_for_c.h
;         so that the C code will have the same values as the 6507 code
;===============================================================================

    SEG.U DISPLAYDATA
    ORG $0000

_DS_TO_ARM:     
_RUN_FUNC:      ds 1        ; function to run
_SWCHA:         ds 1        ; joystick directions to ARM code
_SWCHB:         ds 1        ; console switches to ARM code
_INPT4:         ds 1        ; left firebutton state to ARM code
_INPT5:         ds 1        ; right firebutton state to ARM code
_VB_TIME:       ds 1        ; VB Time Remaining
_OS_TIME:       ds 1        ; OS Time Remaining

_DS_FROM_ARM:
_MODE:          ds 1        ; $00 = splash, $01 = menu, $80 = game 
_BALL_X:        ds 1        ; position of ball
_M1_X:          ds 1        ; position of missile 1
_M0_X:          ds 1        ; position of missile 0
_P1_X:          ds 1        ; position of player 1
_P0_X:          ds 1        ; position of player 0
_ARENA_COLOR:   ds 1

;----------------------------------------
; To save space in RAM we can share the space used by the datastream buffers
; for the Splash, Menu, and Game screens.
;----------------------------------------
    align 4             ; using myMemsetInt to zero out RAM is faster than
                        ; myMemset, but it requires the starting address to be
                        ; 4 byte aligned 


_BUF_JUMP1:         ds (_ARENA_SCANLINES -1 ) * 2         ; long-word align!!
_BUF_JUMP1_EXIT:    ds 2

_BUF_AUDV           ds 2
_BUF_AUDC           ds 2
_BUF_AUDF           ds 2


    ;ds 2 ; bug?
    
;_BOARD              ds 24*40

    ; sonwehere there's a memory overflow which requires this following definition
    ; we're overwriting _board, probably... so needs to be fixed!

;_UNCOVER            ds 6 ;24*40/8+2                ; +2 for word-align speed in clearing (C)

;    align 4


; DO NOT CHANGE ORDER
;{ clear in main.c assumes one block to clear

;------------------------------------------------------------------------------

_BUFFERS = *
_BOARD = *

BUFN SET 0
    MAC DEFBUF ;name
_BUF_{1}    ds ARENA_BUFFER_SIZE
BUFN SET BUFN + 1
    ENDM

;    DEFBUF COLUPF
;    DEFBUF COLUBK
;    DEFBUF PF0_LEFT
;    DEFBUF PF1_LEFT
;    DEFBUF PF2_LEFT
;    DEFBUF PF0_RIGHT
;    DEFBUF PF1_RIGHT
;    DEFBUF PF2_RIGHT
;    DEFBUF GRP0A
;    DEFBUF GRP1A
;
;    DEFBUF COLUP0
;    DEFBUF COLUP1

BSIZE SET 0

;     MAC ALLOC
; _BUF_{1} = _BUFFERS + {2} * _ARENA_SCANLINES
;     IF {2} > BSIZE
; BSIZE SET {2}
;     ENDIF
;     ENDM

;     ALLOC COLUPF, 0
;     ALLOC COLUBK, 1

;     ALLOC PF0_LEFT, 2
;     ALLOC PF1_LEFT, 3
;     ALLOC PF2_LEFT, 4
;     ALLOC PF0_RIGHT, 5
;     ALLOC PF1_RIGHT, 6
;     ALLOC PF2_RIGHT, 7

;     ALLOC GRP0A, 8
;     ALLOC GRP1A, 9
;     ALLOC COLUP0, 10
;     ALLOC COLUP1, 11

;     ds BSIZE * ARENA_BUFFER_SIZE

; _BUFFER_BLOCK_SIZE = * - _BUFFERS


;------------------------------------------------------------------------------




OverlapDisplayDataRam:  ; mark the beginning of overlapped RAM
; Splash screen datastream buffers
;_BUF_SPLASH0:   ds 192
;_BUF_SPLASH1:   ds 192
;_BUF_SPLASH2:   ds 192
;_BUF_SPLASH3:   ds 192

    echo "----",($1000 - *) , "Splash bytes of Display Data RAM left"
;----------------------------------------
; this ORG overlaps the Menu datastreams on top of the Splash datastreams
;----------------------------------------

    ; Generic overlap variable usage 
    ORG OverlapDisplayDataRam
    echo "----",($1000 - *) , "Menu bytes of Example Overlap RAM left"
    
;----------------------------------------
; this ORG overlaps the Game datastreams on top of the Splash and Menu datastreams
;----------------------------------------
    ORG OverlapDisplayDataRam
; Game datastream buffers
_EVERY_FRAME_ZERO_START:

    align 4 ; need to be 4 byte aligned to use myMemsetInt
_EVERY_FRAME_ZERO_COUNT=*-_EVERY_FRAME_ZERO_START   ; end of zeroed out data
   



    echo "----",($1000 - *) , "Game bytes of Display Data RAM left"        