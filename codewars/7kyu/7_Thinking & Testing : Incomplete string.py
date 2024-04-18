def testit(s):
    r = ''
    for i in range(0, len(s), 2):
        r += chr((ord(s[i]) + ord(s[i + 1 if i + 1 < len(s) else i])) // 2)
    return r