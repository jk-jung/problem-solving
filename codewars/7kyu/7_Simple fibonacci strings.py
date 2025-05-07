def solve(n):
    a = '0'
    b = '01'
    for i in range(n):
        a, b = b, b + a
    return a
