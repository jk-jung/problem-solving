def rotate(s):
    r = []
    for _ in range(len(s)):
        s = s[1:] + s[0]
        r.append(s)
    return r