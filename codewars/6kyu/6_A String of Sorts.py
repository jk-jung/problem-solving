def sort_string(s, o):
    def f(x):
        return x[0] + 1000000 if x[1] not in o else o.find(x[1])
    return ''.join([y[1] for y in sorted([x for x in enumerate(s)], key=f)])