from collections import defaultdict, Counter
def group_anagrams(words):
    d = defaultdict(list)
    for x in words:
        d[tuple(sorted(Counter(x).items()))].append(x)
    return list(d.values())
