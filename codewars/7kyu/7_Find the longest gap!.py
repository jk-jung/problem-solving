def gap(num):
    r = 0
    for i in range(1, 50):
        if '1' + '0' * i + '1' in bin(num):
            r = i
    return r
