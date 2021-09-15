def integer_right_triangles(n):
    if n%2: return []
    r = []
    m = n // 2
    for i in range(1, 10000000):
        c = m - i
        ab = i * n
        a_b = i + m

        if c * 3 <= n: break
        if a_b ** 2 - 4 * ab < 0: continue
        a = int((a_b - (a_b ** 2 - 4 * ab) ** .5) // 2)
        b = int(a_b - a)

        if a + b == a_b and a * b == ab:
            r.append([a, b, c])
    return r