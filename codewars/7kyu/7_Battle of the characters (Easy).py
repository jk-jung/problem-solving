def battle(x, y):
    def f(a):
        return sum(ord(c) - ord('A') + 1 for c in a)
    if f(x) == f(y): return 'Tie!'
    return x if f(x) > f(y) else y