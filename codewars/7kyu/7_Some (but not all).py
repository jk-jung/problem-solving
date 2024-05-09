def some_but_not_all(a, b):
    return any(map(b, a)) and not all(map(b, a))
