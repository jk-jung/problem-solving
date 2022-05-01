# Should return triangle type:
#  0 : if triangle cannot be made with given sides
#  1 : acute triangle
#  2 : right triangle
#  3 : obtuse triangle

def triangle_type(a, b, c):
    a, b, c = sorted([a, b, c])
    if c >= a + b: return 0
    c = c * c
    a = a * a
    b = b * b
    if c == a + b: return 2
    return 1 if c < a + b else 3
