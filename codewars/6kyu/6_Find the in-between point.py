def middle_point(x1, y1, z1, x2, y2, z2, x3, y3, z3):
    def f(a, b, c):
        return sorted([(a, 1), (b, 2), (c, 3)])[1][1]
    if x1 != x2: return f(x1, x2, x3)
    if y1 != y2: return f(y1, y2, y3)
    return f(z1, z2, z3)
