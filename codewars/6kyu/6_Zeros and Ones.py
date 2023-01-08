def replace_zero(s):
    s = ''.join(map(str, s)).split('0')
    r, idx, ii = 0, -1, 0

    for i in range(1, len(s)):
        t = len(s[i - 1]) + len(s[i]) + 1
        ii += len(s[i-1])
        if t >= r:
            r, idx = t, ii
        r = max(r, len(s[i - 1]) + len(s[i]) + 1)
        ii += 1
    return idx
