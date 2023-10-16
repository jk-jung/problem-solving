import random
def random_ints(n, total):
    print(n, total)
    r = []
    for i in range(n - 1):
        r.append(random.randint(1, total - (n - i)))
        total -= r[-1]
    return r + [total]
