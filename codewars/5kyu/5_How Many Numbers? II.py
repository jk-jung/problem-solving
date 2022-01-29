def max_sumDig(n, m):
    def ck(x):
        t = []
        while x:
            t.append(x % 10)
            x //= 10
            t = t[-4:]
            if len(t) == 4 and sum(t) > m:
                return False
        return True

    r = [x for x in range(1000, n + 1) if ck(x)]
    mm = sum(r) / len(r)
    t = min(abs(x - mm) for x in r)
    r1 = [x for x in r if abs(x - mm) == t][0]

    return [len(r), r1, sum(r)]
