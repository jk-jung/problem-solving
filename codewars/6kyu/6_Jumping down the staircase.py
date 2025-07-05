from functools import cache

@cache
def get_number_of_ways(a, b):
    if a < 0: return 0
    if a == 0: return 1
    return sum(get_number_of_ways(a - i, b) for i in range(1, b + 1))