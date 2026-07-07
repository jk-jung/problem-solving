def choose_best_home(places, pr, p):
    def f(v):
        r = 0
        for i, k in enumerate(p):
            if v.get(k) == pr[k]:
                r += 6 - i
        return -r

    r = []
    for k, v in places.items():
        r.append((f(v), k))
    return sorted(r)[0][1]
