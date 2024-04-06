def win_round(a, b):
    a = sorted(a, reverse=True)
    b = sorted(b, reverse=True)
    return a[0] * 10 + a[1] > b[0] * 10 + b[1]
