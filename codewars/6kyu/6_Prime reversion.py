def solve(a,b):
    def f(x):
        if x < 2: return False
        i = 2
        while i * i <= x:
            if x % i == 0: return False
            i += 1
        return True

    v = [x for x in range(a, b) if f(x)]
    r = 0
    for x in v:
        for y in v:
            if x <= y and f(sum(map(int, str(x * y)))):
                r += 1
    return r
