def matrix(a):
    for i in range(len(a)):
        if a[i][i] < 0: a[i][i] = 0
        else: a[i][i] = 1
    return a