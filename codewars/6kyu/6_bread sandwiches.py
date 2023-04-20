def slices_to_name(n):
    try:
        if n <= 1: return
        return ' '.join((['bread'] if n % 2 else []) + ['sandwich'] * (n // 2))
    except: return


def name_to_slices(v):
    try:
        v = v.split(' ')
        r = 0
        if v[0] == 'bread':
            r = 1
            v = v[1:]
        if set(v) != {'sandwich'}: return
        return  r + len(v) * 2
    except: return
