def find_missing_number(n):
    v = [0 for i in range(len(n) + 2)]
    for x in n:
        v[x] = 1
    for i in range(1, len(n) + 2):
        if v[i] == 0:
            return i