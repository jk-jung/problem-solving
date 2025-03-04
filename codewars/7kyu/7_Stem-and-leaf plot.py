from collections import defaultdict
def stem_and_leaf(data):
    r = defaultdict(list)
    for x in sorted(data):
        r[x // 10].append(x % 10)
    return r