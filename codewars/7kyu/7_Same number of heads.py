def split_coins(c, k):
    a, b = c[:k], c[k:]
    return [x.flip() for x in a], b
