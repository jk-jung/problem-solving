from itertools import product
def multiiter(*v):
    for x in product(*[range(x) for x in v]):
        yield x
