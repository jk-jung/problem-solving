def next_id(a):
    for i in range(len(a) + 100):
        if i not in a:
            return i
