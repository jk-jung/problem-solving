def evaluate(equation):
    try:
        v = [int(x) for x in equation.split(' @ ')]
        a = v[0]
        for b in v[1:]:
            a = (a + b) + (a - b) + (a * b) + (a // b)
        return a
    except: pass
