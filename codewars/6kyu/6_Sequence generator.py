def sequence_gen(*v):
    v = list(v)
    while True:
        v.append(sum(v))
        yield v.pop(0)
