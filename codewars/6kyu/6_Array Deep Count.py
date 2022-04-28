def deep_count(a):
    if isinstance(a, list):
        return len(a) + sum(deep_count(x) for x in a)
    else: return 0
