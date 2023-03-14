from collections import Counter

def predict(v, polls):
    c = Counter()
    for x, w in polls:
        for i, y in enumerate(x):
            c[i] += y * w / sum([z[1] for z in polls])
    return {x: round(y + 1e-9, 1) for x, y in zip(v, c.values())}
