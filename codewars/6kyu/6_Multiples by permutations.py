from collections import Counter
def search_perm_mult(n_max, k):
    r = 0
    for i in range(1, n_max // k + 1):
        if Counter(str(i)) == Counter(str(i * k)):
            r += 1
    return r