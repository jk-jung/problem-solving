from random import random as r
def area_of_the_shape(f):
    a, b = 10000, 0
    for i in range(a):
        b += f(r(), r())
    return b / a
