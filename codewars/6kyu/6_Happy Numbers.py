
def happy_numbers(n):
    ck = [0 for _ in range(n * 100 + 1)]
    ck[1] = 1
    def f(x):
        if not ck[x]:
            ck[x] = 2
            y = sum(int(k) ** 2 for k in str(x))
            ck[x] = f(y)
        return ck[x]
    return [x for x in range(1, n + 1) if f(x) == 1]
