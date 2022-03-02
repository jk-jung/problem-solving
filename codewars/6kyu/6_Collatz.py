def collatz(n):
    r = []
    while n != 1:
        r.append(n)
        if n % 2 == 0:
            n = n // 2
        else:
            n = 3 * n + 1
    return '->'.join(str(x) for x in r + [1])
