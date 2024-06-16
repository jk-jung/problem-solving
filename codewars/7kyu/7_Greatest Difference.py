def diff(arr):
    if not arr or max(abs(eval(x)) for x in arr) == 0: return False
    return max(arr, key=lambda x: abs(eval(x)))
