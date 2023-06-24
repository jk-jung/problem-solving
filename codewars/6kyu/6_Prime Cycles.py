
t = {
    '0': 1,
    '1': 2,
    '2': 3,
    '3': 5,
    '4': 7,
    '5': 11,
    '6': 13,
    '7': 17,
    '8': 19,
    '9': 23
}

def f(x):
    r = 1
    for k in str(x):r *= t[k]
    return r

def g(n, c):
    if n in c: return c[n]
    c[n] = n
    c[n] = max(c[n], g(f(n), c))
    return c[n]

def find_max(n):
    return g(n, {})
