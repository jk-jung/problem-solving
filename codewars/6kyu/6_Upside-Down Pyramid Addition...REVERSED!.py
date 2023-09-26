def reverse(t):
    y = [t[0]]
    for x in t[1:]:
        z = [x]
        for k in y:
            z.append(k - z[-1])
        y = z
    return y[::-1]
