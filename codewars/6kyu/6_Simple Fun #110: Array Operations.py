def array_operations(a, k):
    if not k: return a
    k -= 1
    a = [max(a) - x for x in a]
    if k % 2: return [max(a) - x for x in a]
    return a
