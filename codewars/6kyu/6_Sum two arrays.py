def sum_arrays(a, b):
    if not a and not b: return a
    if not a: a = [0]
    if not b: b = [0]

    a = int(''.join(map(str, a)))
    b = int(''.join(map(str, b)))
    c = a + b
    t = list(str(abs(c)))
    if c >= 0:
        return list(map(int, t))
    else:
        t[0] = '-' + t[0]
        return list(map(int, t))
