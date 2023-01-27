# return the sum of the two polynomials p1 and p2.
def poly_add(p1, p2):
    print(p1)
    print(p2)
    if len(p1) < len(p2): p1, p2 = p2, p1
    p1 = p1[:]
    for i, x in enumerate(p2):
        p1[i] += x
    return p1
