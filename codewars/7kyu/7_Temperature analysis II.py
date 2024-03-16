def close_to_zero(t):
    if not t: return 0
    v = [int(x) for x in t.split(' ')]
    return min(v, key=lambda x: (abs(x), -x))