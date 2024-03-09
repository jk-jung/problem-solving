from math import ceil

def f(n):
    if n < 0: return 0
    if n == 0: return 1
    r = 1
    m = str(n)
    t = 9
    for i in range(1, len(m)):
        r += t
        if i % 2 == 0: t *= 10

    k = [0 for _ in range(len(m))]
    mm = (len(m) + 1) // 2
    for i in range((len(m) + 1) // 2):
        j = len(m) - i - 1
        for v in range(1 if i == 0 else 0, int(m[i])):
            r += 10 ** (mm - i - 1)
        k[i] = k[j] = int(m[i])
    if int(''.join(map(str, k))) <= n:r += 1
    return r


def count_palindromes(a, b):
    return max(0, f(int(b)) - f(ceil(a) - 1))
