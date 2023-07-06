import math

def max_x(f, delta=1e-6, max_evaluations=30):
    phi = (1 + math.sqrt(5)) / 2  # Golden ratio

    x_left = 0
    x_right = 1

    x1 = x_right - (x_right - x_left) / phi
    x2 = x_left + (x_right - x_left) / phi

    f_x1 = f(x1)
    f_x2 = f(x2)

    for _ in range(max_evaluations - 2):
        if f_x1 < f_x2:
            x_left = x1
            x1 = x2
            x2 = x_left + (x_right - x_left) / phi
            f_x1 = f_x2
            f_x2 = f(x2)
        else:
            x_right = x2
            x2 = x1
            x1 = x_right - (x_right - x_left) / phi
            f_x2 = f_x1
            f_x1 = f(x1)
    return x1