def top3(a, b, c):
    a = sorted(enumerate(a), key=lambda x: (-b[x[0]] * c[x[0]], x[0]))[:3]
    return [x[1] for x in a]