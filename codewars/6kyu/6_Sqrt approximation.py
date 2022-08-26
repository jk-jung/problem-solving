def sqrt_approximation(number):
    i = 1
    while True:
        if i * i == number: return i
        if i * i > number: return [i - 1, i]
        i += 1