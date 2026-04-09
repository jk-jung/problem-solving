def ship_of_theseus(a):
    return all(
        sum((p != q for p, q in zip(x, y))) == 1 and len(x) == len(y)
        for x, y in zip(a, a[1:])
    )
