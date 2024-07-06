def count_sum_of_two_representations(n, l, r):
    t = 0
    for i in range(l, r + 1):
        j = n - i
        if i <= j and j <= r: t += 1
    return t
