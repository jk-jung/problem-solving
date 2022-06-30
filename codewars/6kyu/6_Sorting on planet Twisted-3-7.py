def sort_twisted37(v):
    def f(x):
        x = str(x).replace('3', 'a').replace('7', 'b')
        return int(x.replace('a', '7').replace('b', '3'))
    return sorted(v, key=f)
