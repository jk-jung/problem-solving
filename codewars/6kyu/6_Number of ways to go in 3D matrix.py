from functools import cache


@cache
def f(x, y, z):
    if x < 1 or y < 1 or z < 1:
        return 0
    if x == 1 and y == 1 and z == 1:
        return 1
    return f(x - 1, y, z) + f(x, y - 1, z) + f(x, y, z - 1)


def ways_in_3d_matrix(x, y, z):
    return f(x, y, z)
