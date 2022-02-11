def likes(v):
    if len(v) == 0: v.append('no one')
    if len(v) > 3: v[2] = f'{len(v) - 2} others'

    if len(v) == 1:
        return f'{v[0]} likes this'
    elif len(v) == 2:
        return f'{v[0]} and {v[1]} like this'
    return f'{v[0]}, {v[1]} and {v[2]} like this'
