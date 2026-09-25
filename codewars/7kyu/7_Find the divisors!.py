def divisors(a):
    r = []
    for x in range(2, a):
        if a % x == 0:
            r.append(x)
    return r if r else f"{a} is prime"
