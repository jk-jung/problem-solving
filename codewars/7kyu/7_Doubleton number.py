def doubleton(s):
    while True:
        s += 1
        if len(set(str(s))) == 2: return s