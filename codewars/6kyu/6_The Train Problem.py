def is_valid_train_arrangement(a, b):
    if len(a) != len(b):return False
    if a.replace('.', '') != b.replace('.', ''): return False
    aa = [i for i, x in enumerate(a) if x != '.']
    bb = [i for i, x in enumerate(b) if x != '.']
    for x, y, z in zip(a.replace('.', ''), aa, bb):
        if x == '<' and y < z: return False
        if x == '>' and y > z: return False
    return True
