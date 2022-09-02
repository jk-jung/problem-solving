def assemble(arr):
    r = ''
    for x in zip(*arr):
        x = set(x) - {'*'}
        r += list(x)[0] if len(x) == 1 else '#'
    return r