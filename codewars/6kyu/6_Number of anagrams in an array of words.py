from collections import Counter


def anagram_counter(words):
    c = Counter([tuple(sorted(x)) for x in words])
    return sum(v * (v - 1) // 2 for v in c.values())
