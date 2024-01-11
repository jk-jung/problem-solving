def num_of_open_lockers(n):
    r = 0
    while r * r <= n:r += 1
    return r - 1
    