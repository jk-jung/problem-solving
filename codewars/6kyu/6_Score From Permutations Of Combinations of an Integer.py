from itertools import permutations, combinations
def sc_perm_comb(num):
    n = str(num)
    s = {0}
    for i in range(1, len(n) + 1):
        for c in combinations(n, i):
            for x in permutations(c):
                s.add(int(''.join(x)))
    return sum(s)
