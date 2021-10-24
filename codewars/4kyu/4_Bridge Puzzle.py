def is_prime(s):
    i, c = 2, 0
    while i * i <= s:
        while s % i == 0:
            s //= i
            c += 1
        i += 1
    if s != 1: c += 1
    return c == 1


def statement1(s):
    if s % 2 == 0: return False
    return not is_prime(s - 2)


def statement2(p):
    r = []
    for i in range(2, int(p **.5) + 1):
        if p % i: continue
        a, b = i, p // i
        if not statement1(a + b): continue
        r.append((a, b))
    return len(r) == 1


def statement3(s):
    r = []
    for i in range(2, s // 2):
        a, b = i, s - i
        if statement1(a + b) and statement2(a * b):
            r.append((a, b))
    return len(r) == 1


def is_solution(a, b):
    return statement1(a + b) and statement3(a + b) and statement2(a * b)
