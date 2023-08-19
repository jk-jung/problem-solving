def morse_converter(t):
    s = '1 .---- 2 ..--- 3 ...-- 4 ....- 5 ..... 6 -.... 7 --... 8 ---.. 9 ----. 0 -----'.split(' ')
    r = 0
    while t:
        for i, x in enumerate(s):
            if t.startswith(x):
                t = t[len(x):]
                r = r * 10 + int(s[i-1])
    return r
