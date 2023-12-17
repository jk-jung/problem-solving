def sc(a):
    for i in range(len(a)):
        for j in range(len(a[i])):
            if a[i][j] == 'B': return [i, j]
