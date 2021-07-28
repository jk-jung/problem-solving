d = {}
def fibonacci(n):
    if n in [0, 1]:
        return n
    if n in d: return d[n]
    d[n] = fibonacci(n - 1) + fibonacci(n - 2)
    return d[n]