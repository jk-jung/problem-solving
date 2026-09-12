def f(a, b, c, s):
    if s <= 1:
        return a * s
    if s <= 10:
        return a + (s - 1) * b
    return a + 9 * b + (s - 10) * c

def phone_call(a, b, c, s):
    for i in range(1000000):
        if f(a, b, c, i) > s:
            return i - 1
