def is_sator_square(a):
    n = len(a)
    b = [x[::-1] for x in a[::-1]]
    c = [[a[j][i] for j in range(n)] for i in range(n)]
    return a == b == c