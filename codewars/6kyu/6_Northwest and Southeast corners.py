def box(c):
    a = [x[0] for x in c]
    b = [x[1] for x in c]

    return {
        'nw': [max(a), min(b)],
        'se': [min(a), max(b)]
    }
