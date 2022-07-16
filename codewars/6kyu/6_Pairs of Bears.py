def bears(s, x):
    r, i = '', 1
    while i < len(x):
        t = x[i - 1:i + 1]
        if t in 'B8B':
            r += t
            i += 1
        i += 1

    return [r, len(r) >= s]