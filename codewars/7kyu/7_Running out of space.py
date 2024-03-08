def spacey(array):
    r = ['']
    [r.append(r[-1]+x) for x in array]
    return r[1:]
