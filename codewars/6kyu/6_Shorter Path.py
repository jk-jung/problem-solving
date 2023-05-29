def directions(g):
    y = g.count('N') - g.count('S')
    x = g.count('E') - g.count('W')

    r = ('N' * y if y > 0 else 'S' * -y) + ('E' * x if x > 0 else 'W' * -x)
    return list(r)