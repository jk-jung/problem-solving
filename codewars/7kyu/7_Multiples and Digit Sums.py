def procedure(i):
    return sum(sum(map(int, str(x))) for x in range(i, 101, i))
