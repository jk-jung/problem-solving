import random
def random_case(s):
    def f(x):
        if x.isalpha():
            if random.random() < 0.5: return x.upper()
            return x.lower()
        return x
    return ''.join(f(x) for x in s)
