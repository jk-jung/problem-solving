def length_of_sequence(arr, n):
    a = [i for i, x in enumerate(arr) if x == n]
    return max(a) - min(a) + 1 if len(a) == 2 else 0
