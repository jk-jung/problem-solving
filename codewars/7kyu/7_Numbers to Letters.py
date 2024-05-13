def switcher(v):
    r = ''
    for x in map(int, v):
        if x < 27: r += chr(ord('a') + 26 - x)
        elif x == 27: r += '!'
        elif x == 28: r += '?'
        else: r += ' '
    return r
