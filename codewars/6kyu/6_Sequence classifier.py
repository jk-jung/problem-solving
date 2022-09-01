def sequence_classifier(v):
    if len(set(v)) == 1: return 5

    a, b, c = 0, 0, 0
    for i in range(1, len(v)):
        if v[i - 1] == v[i]: a = 1
        if v[i - 1] < v[i]: b = 1
        if v[i - 1] > v[i]: c = 1
    if b and c: return 0
    if b and a + c == 0: return 1
    if b and a and c == 0: return 2
    if c and a + b == 0: return 3
    return 4

