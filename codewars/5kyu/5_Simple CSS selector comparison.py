def compare(a, b):
    def f(x):
        if x == '*': return 0, 0, 0
        n = len([y for y in x.replace('.', ' ').replace('#', ' ').split(' ') if y])
        c = x.count('.')
        i = x.count('#')
        return i, c, n - c - i

    return a if f(a) > f(b) else b
