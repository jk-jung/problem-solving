def scramble(a, b):
    return "".join(x[1] for x in sorted(zip(b, a)))
