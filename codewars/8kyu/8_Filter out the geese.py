g = ["African", "Roman Tufted", "Toulouse", "Pilgrim", "Steinbacher"]


def goose_filter(b):
    return [x for x in b if x not in g]
