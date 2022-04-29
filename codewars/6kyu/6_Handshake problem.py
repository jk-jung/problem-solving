def get_participants(h):
    for i in range(1, 1000):
        c = i * (i - 1) // 2
        if c >= h: return i
