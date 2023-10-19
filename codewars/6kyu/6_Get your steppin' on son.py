def word_step(s):
    r = []
    for i, x in enumerate(s.split(' ')):
        if i == 0:r.append(list(x))
        elif i % 2 == 0:
            r[-1] += list(x)[1:]
        else:
            t = len(r[-1]) - 1
            for y in x[1:]:
                r.append([' '] * t + [y])
    t = len(r[-1])
    for i in range(len(r)):
        r[i] += [' '] * (t - len(r[i]))
    return r
