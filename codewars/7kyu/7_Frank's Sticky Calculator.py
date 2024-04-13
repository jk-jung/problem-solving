def sticky_calc(a, b, c):
    c = round(c)
    b = int(str(round(b)) + str(c))
    return round(eval(f'{b}{a}{c}'))
