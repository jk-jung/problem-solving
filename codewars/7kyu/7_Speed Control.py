def gps(s, x):
    return max([(b - a) * 3600 / s for a, b in zip(x, x[1:])]) if len(x) > 1 else 0
