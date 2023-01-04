r = [0]
for x in range(6, 107160 + 1):
    s = 0
    for i in range(1, int(x ** .5) + 1):
        if x % i == 0:
            s += i
            if x // i != i:
                s += x // i
    if x ** 3 % s == 0:
        r.append(x)


def int_cube_sum_div(n):
    return r[n]
