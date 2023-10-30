def calculate(s):
    t = []
    for x in s.split(' '):
        if x in '+-*/':
            t.append(x)
        else:
            x = float(x)
            while len(t) >= 2 and isinstance(t[-1], float) and isinstance(t[-2], str):
                y = t.pop()
                o = t.pop()
                x = eval(f"{y} {o} {x}")
            t.append(x)
    return t[0]
