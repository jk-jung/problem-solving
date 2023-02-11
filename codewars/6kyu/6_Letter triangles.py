def triangle(s):
    while len(s) > 1:
        r = ''
        for i in range(1, len(s)):
            t = ord(s[i - 1]) + ord(s[i]) - ord('a') * 2 + 2
            if t > 26: t -= 26
            r += chr(t + ord('a') - 1)
        s = r
    return s
