g = 9.81
def dist(v, mu):
    v = v / 3.6
    return v ** 2 / (2 * mu * g) + v

def speed(d, mu):
    k = 1 / (2 * mu * g)
    return (-1 + (1 + 4 * d * k) ** .5) / (2 * k) * 3.6
