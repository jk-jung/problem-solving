def longest_substring(s):
    r, ck, t = 0, {}, ''
    for x in s:
        if x in ck:
            j = 0
            for i, y in enumerate(t):
                j = i
                del ck[y]
                if y == x:
                    break
            t = t[j + 1:]
        ck[x] = 1
        t += x
        r = max(r, len(t))
    return r
