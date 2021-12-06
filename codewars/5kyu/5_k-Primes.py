MAX = 11000000
prime = [0 for _ in range(MAX)]

for i in range(2, MAX):
    if prime[i]: continue
    for j in range(i + i, MAX, i): prime[j] = i


def cnt(x):
    c = 0
    while prime[x]:
        c += 1
        x //= prime[x]
    if x > 1: c += 1
    return c


def count_Kprimes(k, s, e):
    return [x for x in  range(s, e+1) if cnt(x) == k]


def puzzle(s):
    A = count_Kprimes(1, 2, s + 1)
    B = count_Kprimes(3, 2, s + 1)
    C = count_Kprimes(7, 2, s + 1)

    r = 0
    for a in A:
        for b in B:
            for c in C:
                if a + b + c == s:
                    r += 1

    return r