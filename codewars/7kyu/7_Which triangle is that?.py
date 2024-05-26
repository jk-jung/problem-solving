def type_of_triangle(a, b, c):
    if isinstance(a, int) and isinstance(b, int) and isinstance(c, int):
        a, b, c = sorted([a, b, c])
        if c >= a + b: return "Not a valid triangle"
        if a == b == c: return 'Equilateral'
        if a == b or b == c: return 'Isosceles'
        return 'Scalene'
    return "Not a valid triangle"
