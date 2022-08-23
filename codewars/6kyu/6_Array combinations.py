from functools import reduce

def solve(arr):
    return reduce(lambda x,y : x*y,[len(set(x)) for x in arr])
