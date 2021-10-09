def subsets_parity(n,k):
    def n2(x): return sum(x // 2 ** i for i in range(1, 35))
    b2 = n2(n) - n2(k) - n2(n-k)
    return "EVEN" if b2 > 0 else "ODD"