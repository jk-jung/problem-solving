def get_mean(v, x, y):
    if x ==1 or y == 1 or x > len(v) or y > len(v):return -1
    return sum(v[:x]) / x / 2 + sum(v[-y:]) / y / 2