def reverse_factorial(num):
    r = 1
    for i in range(1, 1000):
        r *= i
        if r == num: return f"{i}!"
    return 'None'
