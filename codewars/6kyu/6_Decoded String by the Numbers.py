def decode(s):
    r, i = [], 0
    while i < len(s):
        if s[i] == '\\' and i + 1 < len(s) and s[i + 1].isdigit():
            i += 1
            t = 0
            while i < len(s) and s[i].isdigit():
                t = t * 10 + int(s[i])
                i += 1
            r.append(s[i:i + t])
            i += t
        else:
            r.append(s[i])
            i += 1
    return r
