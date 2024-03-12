def monty_hall(a, b):
    return round(len([x for x in b if x != a]) / len(b) * 100)
