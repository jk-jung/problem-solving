def jumble(s):
    def f(x):
        s, e = 1, 1

        x = list(x)
        while e < len(x) and x[e].isalnum(): e += 1
        e -= 2
        while s < e:
            if not x[s].isalnum(): s += 1
            elif not x[e].isalnum(): e -= 1
            else:
                x[s], x[e] = x[e], x[s]
                s += 1
                e -= 1
        return ''.join(x)

    return ' '.join(f(x) for x in s.split(' '))
