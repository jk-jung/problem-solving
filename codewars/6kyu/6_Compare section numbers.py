import re
def compare(s1, s2):
    def f(x):
        x = [int(y) for y in x.split('.')]
        while len(x) and x[-1] == 0: x.pop()
        return x
    s1 = f(s1)
    s2 = f(s2)
    if s1 == s2: return 0
    return -1 if s1 < s2 else 1
