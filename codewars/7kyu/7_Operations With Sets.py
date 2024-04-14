def process_2arrays(arr1, arr2):
    a = set(arr1)
    b = set(arr2)
    return [len(a & b), len(a | b) - len(a & b), len(a - b), len(b - a)]
