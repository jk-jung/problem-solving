def solve(n,k):
    n = str(n)

    def f(i, cnt, s=''):
        if i == len(n):return s
        r = f(i + 1, cnt, s + n[i])
        if cnt: r = min(r, f(i + 1, cnt - 1, s))
        return r

    return f(0, k)