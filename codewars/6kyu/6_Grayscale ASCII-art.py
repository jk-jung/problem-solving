GLYPHS = " .,:;xyYX"

def image2ascii(i):
    r = [''.join(GLYPHS[x * 8 // 255] for x in y) for y in i]
    return '\n'.join(r)
