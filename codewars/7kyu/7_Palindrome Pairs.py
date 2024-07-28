def palindrome_pairs(a):
    r = []
    for i, x in enumerate(a):
        for j, y in enumerate(a):
            z = str(x) + str(y)
            if i != j and z == z[::-1]:
                r.append([i, j])
    return r
