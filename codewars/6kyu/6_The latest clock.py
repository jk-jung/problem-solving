from itertools import permutations
def late_clock(v):
    def f(x):
        h = x[0] * 10 + x[1]
        m = x[2] * 10 + x[3]
        return f'{x[0]}{x[1]}:{x[2]}{x[3]}' if h < 24 and m < 60 else f'00:00'
    return max(f(x) for x in permutations(v))
