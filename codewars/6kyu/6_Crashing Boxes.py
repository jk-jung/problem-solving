def crashing_weights(v):
    def f(t):
        for i in range(1, len(t)):
            if t[i - 1] > t[i]: t[i] += t[i - 1]
        return t[-1]
    return [f(list(x)) for x in zip(*v)]
