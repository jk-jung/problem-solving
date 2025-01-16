def count(a, t, x):
    if x==0:return len([y for y in a if y == t])
    return len([y for y in a if (y - t) % x == 0])
