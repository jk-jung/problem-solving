from collections import Counter
def has_subpattern(s):
    if len(set(s)) == len(s): return False
    c = Counter(s).values()

    for i in range(2, len(s) + 1):
        if all(x % i == 0 for x in c): return True

    return False
