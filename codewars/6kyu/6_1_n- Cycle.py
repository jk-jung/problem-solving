def cycle(n):
    x = 1
    ck = {}
    if n % 2 == 0 or n % 5 == 0: return -1
    for i in range(1000000):
        if x in ck: return i - ck[x]
        ck[x] = i
        x %= n
        x *= 10
