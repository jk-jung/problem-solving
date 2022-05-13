def rank(s, we, n):
    def f(t, i):
        r = sum(ord(x) - ord('a') + 2 for x in t.lower())
        return -r * we[i]
    s = [x for x in s.split(',') if x]
    s =[(f(x, i), x) for i, x in enumerate(s)]
    s = sorted(s)

    if len(s) == 0:
        return 'No participants'
    if len(s) < n:
        return 'Not enough participants'
    return s[n - 1][1]
