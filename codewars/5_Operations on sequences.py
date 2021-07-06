# https://en.wikipedia.org/wiki/Brahmagupta%E2%80%93Fibonacci_identity

def reduce(a, b, c, d):
    return [a*c + b*d, abs(a*d - b*c)]

def solve(arr):
    r = [arr[0], arr[1]]
    for i in range(2, len(arr), 2):
        r = reduce(*r, arr[i], arr[i+1])
    return r