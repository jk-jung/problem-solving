def lstzip(a, b, fn):
    return [fn(*x) for x in zip(a, b)]
