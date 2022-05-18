def mineLocation(v):
    for i in range(len(v)):
        for j in range(len(v[i])):
            if v[i][j] == 1:
                return [i, j]