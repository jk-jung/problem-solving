def triangle_perimeter(a):
    r = 0
    a = [a.a, a.b, a.c]
    for i in range(3):
        x, y = a[i], a[(i + 1) % 3]
        r += ((x.x - y.x) ** 2 + (x.y - y.y) ** 2) ** .5
    return r
