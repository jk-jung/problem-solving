def narcissistic(v):
    return sum(int(x) ** len(str(v)) for x in str(v)) == v
