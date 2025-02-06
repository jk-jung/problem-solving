def partlist(arr):
    r = []
    for i in range(1, len(arr)):
        a, b = arr[:i], arr[i:]
        r.append((' '.join(a), ' '.join(b)))
    return r
