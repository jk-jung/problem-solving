def subsequence_sums(a, qs):
    n = len(a)
    d = [a[0] for _ in range(n)]
    s = [a[0] for _ in range(n)]
    for i in range(1, n):
        d[i] = a[i] * (i + 1) + d[i - 1]
        s[i] = a[i] + s[i - 1]

    def get(l, r):
        a = d[r - 1] - (0 if l == 1 else d[l - 2])
        b = s[r - 1] - (0 if l == 1 else s[l - 2])
        return a - b * (l - 1)

    return [get(*x) for x in qs]
