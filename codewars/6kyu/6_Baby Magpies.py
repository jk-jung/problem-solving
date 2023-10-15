def child(a, b):
    return 1 <= sum(1 if x != y else 0 for x, y in zip(a, b)) <= 2

def grandchild(a, b):
    if len(a) == 1 and a != b:return False
    return sum(1 if x != y else 0 for x, y in zip(a, b)) <= 4
