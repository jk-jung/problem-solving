def boxes_packing(a, b, c):
    l = sorted(zip(a, b, c), key=lambda x: -x[0] * x[1] * x[2])
    l = [sorted(list(x)) for x in l]
    for i in range(1, len(l)):
        for j in range(3):
            if l[i - 1][j] <= l[i][j]:
                return False
    return True
