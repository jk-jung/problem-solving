def positive_to_negative(a):
    for i in range(len(a)):
        a[i] ^= 1
    k = 1
    for i in range(len(a) -1, -1, -1):
        a[i] += k
        if a[i] >= 2:
            a[i] -= 2
            k = 1
        else: k = 0
    return a
