def compute_depth(n):
    s = set()
    for i in range(1, 1000):
        s |= set(str(n * i))
        if len(s) == 10:
            return i
