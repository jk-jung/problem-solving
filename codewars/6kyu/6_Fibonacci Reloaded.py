v = [0, 0, 1]
[v.append(v[-1] + v[-2]) for i in range(100000)]
def fib(n): return v[n]