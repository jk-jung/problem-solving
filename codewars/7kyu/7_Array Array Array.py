def explode(a):
    if isinstance(a[0], str) and isinstance(a[1], str):
        return 'Void!'
    elif isinstance(a[0], str):
        return [a] * a[1]
    elif isinstance(a[1], str):
        return [a] * a[0]
    return [a] * sum(a)
