from collections import Counter
def anagram_difference(words):
    r = 0
    for c in set(''.join(words)):
        v = [x.count(c) for x in words]
        r += sum(v) - min(v) * len(words)
    return r