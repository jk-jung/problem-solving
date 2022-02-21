def digits_product(n):
    if n < 10: return 10 + n
    r = []
    for i in range(9, 1, -1):
        while n % i == 0:
            r.append(str(i))
            n /= i
    if n != 1:
        return -1
    return int(''.join(sorted(r)))
