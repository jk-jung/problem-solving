def variance(w):
    w = [len(x) for x in w]
    return round(sum((x - sum(w) / len(w)) ** 2 for x in w) / len(w), 4)
