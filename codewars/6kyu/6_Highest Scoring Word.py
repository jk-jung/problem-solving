def high(x):
    def f(y): return (sum(-'abcdefghijklmnopqrstuvwxyz'.find(i) - 1 for i in y[1]), y[0])
    return sorted([y for y in enumerate(x.split())], key=f)[0][1]