from collections import Counter
def find_arr(a, b, t, w):
    a, b = Counter(a), Counter(b)
    a = {x for x, y in a.items() if y >= 2}
    b = {x for x, y in b.items() if y >= 2}
    return sorted([x for x in a & b if (1 if w == 'odd' else 0) == x % 2 and t[0] <= x <= t[1]])
