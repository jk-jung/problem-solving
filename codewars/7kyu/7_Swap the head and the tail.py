def swap_head_tail(a):
    if len(a) <= 1: return a
    n = len(a) // 2
    x = a[:n]
    a[:n] = a[-n:]
    a[-n:] = x
    return a
