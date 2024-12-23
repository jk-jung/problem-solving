def last_survivor(a, b): 
    a = list(a)
    while b:
        del a[b.pop(0)]
    return ''.join(a)