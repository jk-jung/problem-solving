def naughty_number(a):
    for i, x in enumerate(a):
        if isinstance(x, list):
            t = naughty_number(x)
            if t is not None:
                return i
        else:
            return i
