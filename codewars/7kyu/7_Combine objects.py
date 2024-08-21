from collections import Counter
def combine(*a):
    return sum(map(Counter, a), Counter())
