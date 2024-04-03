def say_me_operations(a):
    a = list(map(int, a.split(' ')))
    r = []
    for i in range(len(a) - 2):
        x, y, z = a[i:i+3]
        if x + y == z: r.append('addition')
        elif x - y == z: r.append('subtraction')
        elif x * y == z: r.append('multiplication')
        else: r.append('division')
    return ', '.join(r)
