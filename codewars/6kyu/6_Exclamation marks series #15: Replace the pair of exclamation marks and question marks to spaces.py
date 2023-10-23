from itertools import groupby
def replace(s):
    v = [''.join(v) for k, v in groupby(s)]
    while True:
        done = True

        for i in range(len(v)):
            for j in range(i + 1, len(v)):
                x, y = v[i], v[j]
                if len(x) == len(y) and {x[0], y[0]} == {'!', '?'}:
                    done = False
                    v[i] = v[j] = ' ' * len(x)

        if done:
            break

    return ''.join(v)
