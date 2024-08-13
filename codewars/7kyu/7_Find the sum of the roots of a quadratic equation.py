def roots(a,b,c):
    t = b * b - 4 * a * c
    if t < 0: return None
    return round(-b / a, 2)
