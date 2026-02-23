def f(x, y):
    if y == "g":
        return x / 1000
    if y == "mg":
        return x / 1000**2
    if y == "μg":
        return x / 1000**3
    if y == "lb":
        return x * 0.453592
    return x


def solution(a, b):
    x = f(a[0], b[0])
    y = f(a[1], b[1])
    l = a[2]
    if b[2] == "cm":
        l /= 100
    if b[2] == "mm":
        l /= 1000
    if b[2] == "μm":
        l /= 1000**2
    if b[2] == "ft":
        l *= 0.3048

    return 6.67 * x * y / 10**11 / l / l
