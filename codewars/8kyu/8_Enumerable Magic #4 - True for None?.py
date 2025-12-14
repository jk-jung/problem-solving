def none(a, b):
    return all([not b(x) for x in a])
