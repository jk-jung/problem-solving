def frame(t, c):
    t = [f' {x} ' for x in t]
    n = max(map(len, t))
    t = '\n'.join(c + x + " " * (n - len(x)) + c for x in t)
    return '\n'.join([c * (n + 2), t, c * (n + 2)])