def stalin_sort(a):
    i = 1
    while i < len(a):
        if a[i] < a[i - 1]:
            a.pop(i)
        else:
            i += 1
