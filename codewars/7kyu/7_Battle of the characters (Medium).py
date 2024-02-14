def battle(x: str, y: str) -> str:
    def f(a):
        return sum((ord(k) - ord('a') + 1) / 2 if k.islower() else (ord(k) - ord('A') + 1) for k in a)
    if f(x) == f(y): return 'Tie!'
    return x if f(x) > f(y) else y
