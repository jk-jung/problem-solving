def is_prime(x):
    return x > 1 and int(all(x % i != 0 for i in range(2, int(x ** .5) + 1)))