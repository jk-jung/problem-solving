import random
def find_random_seed(lst):
    for i in range(10000):
        random.seed(i)
        t = [random.randrange(0, 101) for _ in range(len(lst))]
        if t == lst: return i
