def balance(a, b):
    def f(x):
        return x.count('!') * 2 + x.count('?') * 3
    a, b = f(a), f(b)

    if a == b:return 'Balance'
    return 'Left' if a > b else 'Right'