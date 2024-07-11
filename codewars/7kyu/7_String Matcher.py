from collections import Counter
def is_matching(a, b, c):
    a = Counter(a.lower().replace(' ', ''))
    b = Counter((b.lower() + c.lower()).replace(' ', ''))
    return a == b
