from collections import Counter, defaultdict
def cards_and_pero(s):
    c = defaultdict(Counter)
    for i in range(0, len(s), 3):
        x = s[i:i + 3]
        c[x[0]][x] += 1
    if any(any(x > 1 for x in y.values()) for y in c.values()): return [-1,-1,-1,-1]
    return [13 - len(c[x]) for x in "PKHT"]
