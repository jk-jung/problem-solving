def is_onion_array(a):
    for i in range(len(a)):
        j = len(a) - 1- i
        if j >= 0 and j != i and a[i] + a[j] > 10:
            return False
    return True
