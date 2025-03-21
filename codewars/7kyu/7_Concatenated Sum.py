def f(n, t):
    if n < 0:
        return -f(-n, t)
    r = 0
    for x in str(n):
        for i in range(t):
            r += 10 ** i * int(x)
    return r


def check_concatenated_sum(n, t):
    return f(n, t) == n
