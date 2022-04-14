from itertools import groupby

def longest_repetition(s):
    a, b = '', 0
    for x in groupby(s):
        t = len(list(x[1]))
        if b < t:
            a = x[0]
            b = t
    return (a, b)