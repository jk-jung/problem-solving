def find_max(r):
    if r is None: return -1e10
    return max(r.value, find_max(r.left), find_max(r.right))
