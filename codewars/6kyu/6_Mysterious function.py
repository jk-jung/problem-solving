def get_num(n):
    d = {'0': 1, '6': 1, '8': 2, '9': 1}
    return sum(d.get(x, 0) for x in str(n))