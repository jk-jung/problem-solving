def dirReduc(arr):
    op = {'W':0, 'N': 1, 'E':2, 'S':3}
    for i in range(len(arr) - 1):
        j = i+1
        d = op[arr[i][0]] - op[arr[j][0]]
        if d == 2 or d == -2:
            return dirReduc(arr[:i] + arr[i+1:j] + arr[j+1:])
    return arr