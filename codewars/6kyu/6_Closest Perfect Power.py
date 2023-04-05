def closest_power(n):
    if n <= 0:return 4
    r = []
    for k in range(2, 100):
        a = n ** (1 / k)
        r.append(min([(abs(n - i ** k), i ** k)for i in range(int(a) - 10, int(a) + 10)]))
        if a < 1.1: break
    return min(r)[1]
