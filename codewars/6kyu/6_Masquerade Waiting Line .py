def friend_find(v):
    r = 0
    for i in range(len(v)):
        if v[i] == 'red':
            if i - 2 >= 0 and v[i-2:i] == ['blue', 'blue']: r += 1
            elif i + 2 < len(v) and v[i + 1: i + 3] == ['blue', 'blue']: r += 1
            elif i - 1 >= 0 and i + 1 < len(v) and [v[i-1], v[i+1]] == ['blue', 'blue']: r += 1
    return r
