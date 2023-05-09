import math
def approx_fraction(x, rel_error):
    if abs(round(x) - x) < 1e-9: return f"There is no need to have a fraction for {round(x)}"
    flag = False
    if x < 0:
        flag = True
        x = -x

    a, b = 1, 1
    while True:
        dif =  (x - a / b ) / x * 100
        if abs(dif) <= rel_error: break
        if dif < 0:b += 1
        else: a += 1
    return [f'{"-" * flag}{a}/{b}', a + b - 2]
