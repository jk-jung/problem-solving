# functions should not return any values
# (: Happy coding! :)

def f(x, k):
    mult(x, 2, k)

def g(x,k):
    z = None
    def t(y):
        nonlocal z
        z = y
    mult(x, 10, t)
    add(z, 1, k)


def main(k):
    z = None
    def t(y):
        nonlocal z
        z = y
    g(2, t)
    f(z, t)
    show(z, k)
