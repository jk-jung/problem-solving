def enough_ink(image, r, g, b):
    for x in sum(image, []):
        r -= (255 - bytes.fromhex(x[:2])[0])
        g -= (255 - bytes.fromhex(x[2:4])[0])
        b -= (255 - bytes.fromhex(x[4:])[0])
    return r >= 0 and g >= 0 and b >= 0
