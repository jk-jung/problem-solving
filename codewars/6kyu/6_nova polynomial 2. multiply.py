# return the product of the two polynomials p1 and p2.
def poly_multiply(a, b):
    r = [0 for _ in range(len(a) + len(b) - 1)]
    for i, x in enumerate(a):
        for j, y in enumerate(b):
            r[i + j] += x * y
    if set(r) == {0}: return []
    return r