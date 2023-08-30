def is_happy(n):
    def f(k):
        return sum([int(x) ** 2 for x in str(k)])
    for i in range(1000):
        if n == 1: return True
        n = f(n)
    return False
