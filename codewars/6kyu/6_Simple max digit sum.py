def solve(n):
    n = str(n)

    def f(x): return (sum(map(int, x)), int(x))
    r = [f(n)]
    pr = ''
    for i in range(len(n)):
        if int(n[i]) > 0:
            r.append(f(pr + str(int(n[i]) - 1) + '9' * (len(n) - i - 1)))
        pr += n[i]

    return max(r)[1]