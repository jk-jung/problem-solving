def get_dividers(v, c):
    r = []
    def f(i, x=1):
        if i == len(v): r.append(x)
        else:
            for j in range(c[i] + 1):
                f(i + 1, x * v[i]**j)
    f(0)
    return sorted(r)
