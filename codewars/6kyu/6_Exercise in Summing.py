def minimum_sum(values, n):
    if not n: return 0
    return sum(sorted(values)[:n])


def maximum_sum(values, n):
    if not n: return 0
    return sum(sorted(values)[-n:])
