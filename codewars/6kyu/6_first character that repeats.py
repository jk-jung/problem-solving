from collections import Counter
def first_dup(s):
    c = Counter(s)
    for i in s:
        if c[i] >= 2: return i
    return