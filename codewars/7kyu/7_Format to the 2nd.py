def print_nums(*v):
    if not v: return ''
    v = [str(x) for x in v]
    m = max(map(len, v))
    return '\n'.join(('0' * 1000 + x)[-m:] for x in v)
