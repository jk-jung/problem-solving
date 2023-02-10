def running_average():
    r = []
    def f(x):
        r.append(x)
        return round(sum(r)/len(r), 2)
    return f
