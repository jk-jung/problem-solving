def count_skills(t, rr):
    t[0] = -1
    x = [0 for _ in range(len(t))]
    for r in rr:
        x[r] = 1
        while t[r] != -1:
            r = t[r]
            if x[r]: break
            x[r] = 1
    return sum(x)