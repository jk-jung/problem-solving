def solve_for_x(eq):
    eq = eq.replace('=', '==')
    for i in range(-1000, 1000):
        x = i
        if eval(eq):
            return i
