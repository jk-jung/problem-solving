def find_smallest(v, k):
    return min(enumerate(v), key=lambda x:x[1])[k == 'value']
