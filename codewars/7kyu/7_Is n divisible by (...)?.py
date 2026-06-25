def is_divisible(*a):
    return all(a[0] % x == 0 for x in a)
