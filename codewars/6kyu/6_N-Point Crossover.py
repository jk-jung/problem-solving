def crossover(ns, xs, ys):
    a, b = [], []

    for i in range(len(xs)):
        if i in ns: xs, ys = ys, xs
        a.append(xs[i])
        b.append(ys[i])
    return a, b