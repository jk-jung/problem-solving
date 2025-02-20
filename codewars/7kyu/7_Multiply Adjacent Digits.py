def digit_multiplication(a):
    r = ''
    for x in a:
        if r and r[-1].isdigit() and x.isdigit():
            r += '*'
        r += x
    return eval(r)