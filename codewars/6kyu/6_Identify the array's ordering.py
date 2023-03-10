def order_type(v):
    def f(x):
        if isinstance(x, int): x = str(x)
        return len(x)
    v = [f(x) for x in v]
    if len(set(v)) <= 1: return 'Constant'
    if sorted(v) == v: return 'Increasing'
    if sorted(v) == v[::-1]: return 'Decreasing'
    return 'Unsorted'