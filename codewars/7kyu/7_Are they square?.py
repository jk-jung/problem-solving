def is_square(v):
    if not v:return
    return all(int(x ** .5) ** 2 == x for x in v)
