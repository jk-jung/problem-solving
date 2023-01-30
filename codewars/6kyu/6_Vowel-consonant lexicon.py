def solve(s):
    a = sorted([x for x in s if x in 'aeiou'])
    b = sorted([x for x in s if x not in 'aeiou'])
    if abs(len(a) - len(b)) >= 2: return 'failed'
    def f(x, y): return ''.join([''.join([a, b]) for a, b in zip(x, y)])
    if len(a) == len(b) or len(a) > len(b): return f(a, b + [''])
    return f(b, a + [''])
