from collections import Counter


def word_square(t):
    n = int(len(t) ** 0.5)
    if n * n != len(t): return False
    return sum(x % 2 for x in Counter(t).values()) <= n
