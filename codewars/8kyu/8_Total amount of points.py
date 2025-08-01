def points(g):
    def f(s):
        if s[0] == s[2]: return 1
        return 0 if s[0] < s[2] else 3
    return sum(f(x) for x in g)
