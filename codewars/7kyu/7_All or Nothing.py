def possibly_perfect(a, b):
    return all(x == '_' or x == y for x, y in zip(a, b)) or all(x == '_' or x != y for x, y in zip(a, b))