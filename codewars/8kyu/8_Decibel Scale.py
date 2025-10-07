from math import log


def db_scale(a):
    return 10 * log(a, 10) + 120
