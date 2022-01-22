def patch_data(s):
    i, r = 0, ''
    while i < len(s):
        l = ord(s[i]) + ord(s[i + 1]) * 256
        r += s[i:i + l + 2] + '\xf4\x01'
        i += l + 4
    return r
