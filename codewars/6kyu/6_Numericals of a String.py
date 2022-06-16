from collections import Counter
def numericals(s):
    r, c = [], Counter()
    for x in s:
        c[x] += 1
        r.append(str(c[x]))
    return ''.join(r)