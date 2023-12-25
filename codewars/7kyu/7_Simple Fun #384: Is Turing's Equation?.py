def is_turing_equation(s):
    a, b = s[::-1].split('=')
    x, y = b.split('+')
    return int(x) + int(y) == int(a)
