def range_function(a, b=None, c=None):
    if b is None: return range(1, a+1)
    if c is None: return range(a, b+1)
    return range(a, c+1, b)
