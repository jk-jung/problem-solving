def pyramid_height(n):
    l = 1
    while n >= l * l:
        n -= l * l
        l += 1
    return l - 1