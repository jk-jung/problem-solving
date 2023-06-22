def sort_photos(v):
    v = sorted([list(map(int, x.split('.img'))) for x in v])[-5:]
    v += [[v[-1][0], v[-1][1] + 1]]
    def f(x):
        return f'{x[0]}.img{x[1]}'
    return list(map(f, v))