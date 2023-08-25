def matrix_elements_sum(m):
    r = 0
    for i in range(len(m)):
        for j in range(len(m[0])):
            if i and m[i-1][j] == 0: m[i][j] = 0
            r += m[i][j]
    return r
