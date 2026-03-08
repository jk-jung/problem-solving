def permutation_free(n, l):
    d = {}

    def go(i, st):
        if len(st) == n:
            return 0
        if i == l:
            return 1

        k = (i, st)
        if k in d:
            return d[k]
        r = 0
        for j in range(n):
            t = str(j) + st
            nt = ""
            for x in t:
                if x in nt:
                    break
                nt += x
            r = (r + go(i + 1, nt)) % 12345787

        d[k] = r
        return r

    return go(0, "")
