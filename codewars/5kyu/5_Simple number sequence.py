def missing(s):
    for i in range(1, len(s)):
        cnt, t, a, r = 0, s, s[:i], -1
        while t and cnt <= 1:
            if t[:len(a)] == a: t = t[len(a):]
            else: cnt, r = cnt + 1, int(a)
            a = str(int(a) + 1)
        if not t and cnt <= 1: return r
    return -1
