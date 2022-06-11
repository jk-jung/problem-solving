def my_first_interpreter(s):
    r, t = '', 0
    for x in s:
        if x == '+': t = (t + 1) % 256
        elif x == '.': r += chr(t)
    return r
