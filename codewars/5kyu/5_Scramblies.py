def g(s):
    d = [0 for _ in range(26)]
    for x in s: d[ord(x) - ord('a')] += 1
    return d


def scramble(s1, s2):
    for x, y in zip(g(s1), g(s2)):
        if x < y: return False
    return True
