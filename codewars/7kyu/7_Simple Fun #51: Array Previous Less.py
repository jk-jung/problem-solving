def array_previous_less(a):
    return [next((x for x in a[:i][::-1] if x < a[i]), -1) for i in range(len(a))]
