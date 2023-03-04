def vowel_shift(s, n):
    if not s: return s
    v = [i for i, x in enumerate(s) if x in 'aeiouAEIOU']
    r = ''
    for i, x in enumerate(s):
        j = v.index(i) if i in v else -1
        if j != -1: r += s[v[(j - n) % len(v)]]
        else: r += x
    return r
