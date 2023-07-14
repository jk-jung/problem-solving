def generate_all_possible_matches(k):
    r = []
    def f(t = [(0, 0)]):
        if max(t[-1]) == k:
            r.append(t)
        else:
            f(t + [(t[-1][0] + 1, t[-1][1])])
            f(t + [(t[-1][0], t[-1][1] + 1)])
    f()
    return [[f'{x[0]}:{x[1]}' for x in y] for y in r]
