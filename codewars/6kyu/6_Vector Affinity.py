def vector_affinity(a, b):
    if len(a) + len(b) == 0: return 1
    return sum(x == y for x, y in zip(a, b)) / max(len(a), len(b))
