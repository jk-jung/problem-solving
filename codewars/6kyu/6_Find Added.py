from collections import Counter
def findAdded(a, b):
    a, b = Counter(a), Counter(b)
    return ''.join(sorted(x * max(0, y - a[x]) for x, y in b.items()))
