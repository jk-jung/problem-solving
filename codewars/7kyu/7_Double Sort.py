def db_sort(v):
    return sorted(v, key=lambda x: (isinstance(x, str), x))
