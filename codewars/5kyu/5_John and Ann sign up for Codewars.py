dj = {}
da = {}


def j(n):
    if n == 0: return 0
    if n in dj: return dj[n]

    dj[n] = n - a(j(n - 1))
    return dj[n]


def a(n):
    if n == 0: return 1
    if n in da: return da[n]

    da[n] = n - j(a(n - 1))
    return da[n]


def john(n):
    return [j(x) for x in range(n)]


def ann(n):
    return [a(x) for x in range(n)]


def sum_john(n):
    return sum(john(n))


def sum_ann(n):
    return sum(ann(n))
