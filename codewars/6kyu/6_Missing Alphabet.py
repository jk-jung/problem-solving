def insert_missing_letters(s):
    r, used = '', set()
    for x in s:
        r += x
        if x in used: continue
        used.add(x)
        for i in range(26):
            a = chr(ord('a') + i)
            b = chr(ord('A') + i)
            if a in s: continue
            if a > x: r += b
    return r
