def revamp(s):
    s = [''.join(sorted(x)) for x in s.split()]
    return ' '.join(sorted(s, key=lambda x: (sum(map(ord, x)), len(x), x)))
