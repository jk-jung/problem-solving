def evaluate_polynomial(a, x):
    r, k = 0, 1
    for i, y in enumerate(a[::-1]):
        r += k * y
        k *= x
    return r
