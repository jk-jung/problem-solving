def variance(v):
    m = sum(v) / len(v)
    return sum((x - m) ** 2for x in v) / len(v)