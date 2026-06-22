def fly_by(a, b):
    return (len(b) * "o" + a[len(b) :])[: len(a)]
