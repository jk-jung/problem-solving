def blind_number(n):
    a, b = 0, 1
    for i in range(n):
        a, b = b, (a + b) * 2
        a %= 1000000007
        b %= 1000000007
    return (a + b) % 1000000007
