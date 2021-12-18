def all_fibonacci_numbers():
    a1, a2 = 1, 1
    while True:
        yield a1
        a1, a2 = a2, a1 + a2
