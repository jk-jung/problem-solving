def triangle_area(t):
    a, b, c, = t.a, t.b, t.c
    r = a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y
    return abs(r) / 2
