from random import sample
def number_generator():
    return sorted(sample(range(1, 50), 6)) + sample(range(10), 1)

def check_for_winning_category(a, b):
    c = len(set(a[:-1]) & set(b[:-1]))
    if c < 2: return -1
    r = (7 - c) * 2 - (a[6] == b[6])
    return -1 if r == 10 else r
