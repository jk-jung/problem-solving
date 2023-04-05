def cipher26(s):
    r, v = '', 0
    for x in s:
        z = ord(x) - ord('a')
        y = z - v
        if y < 0: y += 26
        r += chr(y + ord('a'))
        v = (v + y) % 26
    return r
