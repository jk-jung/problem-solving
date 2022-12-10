def avoid_obstacles(v):
    v = set(v)
    for x in range(1, 102):
        ok = True
        t = {i * x for i in range(101)}
        if not (t & v):
            return x
