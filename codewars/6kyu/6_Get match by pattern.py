from collections import Counter
def find_matched_by_pattern(v):
    def f(s):
        try:
            ck = Counter()
            t = []
            for x in v:
                t.append(s.index(x, ck[x]))
                ck[x] = t[-1] + 1
            return t == sorted(t)
        except:
            return False
    return f
