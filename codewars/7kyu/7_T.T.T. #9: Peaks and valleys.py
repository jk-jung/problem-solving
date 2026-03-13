def peak_and_valley(a):
    r = []
    for i in range(3, len(a) - 3):
        x = a[i - 3 : i]
        y = a[i]
        z = a[i + 1 : i + 4]
        if (max(x) < y > max(z)) or (min(x) > y < min(z)):
            r.append(y)
    return r
