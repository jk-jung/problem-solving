def find_dup(v):
    return sum(v) - len(v) * (len(v) - 1) // 2
