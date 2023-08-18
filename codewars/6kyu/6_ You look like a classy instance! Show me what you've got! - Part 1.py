def show_me(x):
    n = str(x.__class__).split('.')[-1].split("'")[0]
    t = [y for y in dir(x) if '__' not in y]
    if len(t) >= 2:
        t = ', '.join(t[:-1]) + ' and ' + t[-1]
    else:
        t = t[0]
    return f"Hi, I'm one of those {n}s! Have a look at my {t}."
