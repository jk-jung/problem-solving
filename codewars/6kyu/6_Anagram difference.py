from collections import Counter
def anagram_difference(a, b):
    return  sum([abs(Counter(a)[x] - Counter(b)[x]) for x in Counter(a + b)])