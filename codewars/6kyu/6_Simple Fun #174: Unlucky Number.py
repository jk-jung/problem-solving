def unlucky_number(n):
    r = 0
    for x in range(0, n + 1, 13):
        if not(set(str(x)) & {'4', '7'}):
            r += 1
    return r
