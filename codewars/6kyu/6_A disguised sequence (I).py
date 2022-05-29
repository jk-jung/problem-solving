def f(n):
    f1 = d[n - 2]
    f2 = d[n - 1]
    return 6 * f1 * f2 // (5 * f1 - f2)

d = [0 for i in range(10000)]
d[0] = 1
d[1] = 2
for i in range(2, 10000):
    d[i] = f(i)

def fcn(n):
    return d[n]