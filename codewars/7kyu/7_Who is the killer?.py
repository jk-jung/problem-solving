def killer(a, b):
    for k, v in a.items():
        if len(set(v) & set(b)) == len(b):
            return k
