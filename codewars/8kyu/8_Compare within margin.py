def close_compare(a, b, m=0):
    if a < b - m:
        return -1
    if a > b + m:
        return 1
    return 0
