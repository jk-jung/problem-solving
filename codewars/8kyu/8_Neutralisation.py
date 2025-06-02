def neutralise(a, b):
    return ''.join(map(lambda x: x[0] if x[0] == x[1] else '0', zip(a, b)))