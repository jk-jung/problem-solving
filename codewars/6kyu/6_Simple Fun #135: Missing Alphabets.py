from collections import Counter
def missing_alphabets(s):
    c = Counter(s).most_common(1)[0][1]
    return ''.join(x * (c - s.count(x)) for x in 'abcdefghijklmnopqrstuvwxyz')