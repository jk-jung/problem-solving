def accum(s):
    return '-'.join(x.upper() + x.lower() * i for i, x in enumerate(s))