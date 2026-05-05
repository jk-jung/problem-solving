def mean(a):
    p = sum([int(x) for x in a if x.isdigit()])
    q = "".join([x for x in a if x.isalpha()])
    return [p / 10, q]
