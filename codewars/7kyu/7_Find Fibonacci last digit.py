def get_last_digit(n):
    a, b = 0, 1
    for i in range(n):
        a, b = b, a + b
    return a % 10
