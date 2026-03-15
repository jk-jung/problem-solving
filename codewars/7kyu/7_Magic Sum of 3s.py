def magic_sum(a):
    return sum(x for x in a if "3" in str(x) and x % 2)
