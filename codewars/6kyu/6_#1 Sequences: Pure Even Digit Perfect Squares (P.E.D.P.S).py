def even_digit_squares(a, b):
    x = int(a ** .5)
    x += x % 2
    r = []
    while x * x <= b:
        if x * x >= a and all(c in '02468' for c in str(x * x)):
            r.append(x * x)
        x += 2
    return r
