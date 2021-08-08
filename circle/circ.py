

import math

scanLines = 198
desiredPlanetRadiusPixels = 84 #int(scanLines / 2)
textureWidth = 20
pixelRatio = 5.5

full180 = desiredPlanetRadiusPixels * 2
for line in range(3, full180, 3):
    v = line - desiredPlanetRadiusPixels
    offsetText = math.sqrt(desiredPlanetRadiusPixels * desiredPlanetRadiusPixels - (v * v)) / pixelRatio
        #\
        #/ desiredPlanetRadiusPixels * textureWidth
    offset = int(offsetText + 0.5)
    #print("offset", offset)
    bits = 0
    for subPix in range(0, offset):

        realAngle = math.degrees(math.asin((subPix + 0.5)/offset))
        texturePix = realAngle * (textureWidth) / 90

        #
        # fracSub = (subPix + 0.5) * 90 / offset
        # offsetSub = int(math.sin(math.radians(fracSub)) * textureWidth)
        # bits |= (1 << offsetSub)
        bits |= (1 << (19-int(texturePix + 0.5)))

    print(format(bits, '#032b') + ', //', line)

for line in range(full180, 198):
    print("0,")

planetHeight = 20 * 24
halfHeight = planetHeight / 2

for line in range(3, full180, 3):
    v = line - desiredPlanetRadiusPixels
    angle = math.degrees(math.acos(-v/desiredPlanetRadiusPixels))
    length = int(angle * planetHeight / 180)
    length = int(length / 3) * 3

    row = int(length/24)
    col = (length - row * 24) / 3
    col = int(col) * 3
    length = (row << 5) + col

    print(int(length), ', //', line)

    #print("offset", offset)
#     bits = 0
#     for subPix in range(0, offset):
#
#         realAngle = math.degrees(math.asin((subPix + 0.5)/offset))
#         texturePix = realAngle * (textureWidth) / 90
#
#         #
#         # fracSub = (subPix + 0.5) * 90 / offset
#         # offsetSub = int(math.sin(math.radians(fracSub)) * textureWidth)
#         # bits |= (1 << offsetSub)
#         bits |= (1 << (19-int(texturePix + 0.5)))
#
#     print(format(bits, '#032b') + ', //', line)
#
# for line in range(full180, 198):
#     print("0,")






















# for line in range(0, desiredPlanetRadiusPixels, 3):
#     cosine = line / desiredPlanetRadiusPixels
#     angle = math.degrees(math.asin(1 - cosine))
#     length = halfHeight * (90-angle)/90
#     #
#     #
#     #
#     # ang = cosine * 90;
#     # length = math.sin(math.radians(ang)) * (halfHeight - 1)
#     length = int(length/3) * 3
#
#     row = int(length/24)
#     col = (length - row * 24) / 3
#     col = int(col) * 3
#     length = (row << 5) + col
#
#     print(int(length), ', //', line)
# #    print(int(length), ', //', line+1)
# #    print(int(length), ', //', line+2)
#
# for line in range(desiredPlanetRadiusPixels, 0, -1):
#     cosine = line / desiredPlanetRadiusPixels
#     angle = 180 - math.degrees(math.asin(cosine))
#
#     length = halfHeight - halfHeight * (90-angle)/90
#     length = int(length/3) * 3
#
#     row = int(length/24)
#     col = (length - row * 24) / 3
#     col = int(col) * 3
#
#     length = (row << 5) + col
#
#     print(int(length), ', //', line)
# #    print(int(length), ', //', line+1)
# #    print(int(length), ', //', line+2)
#
#
