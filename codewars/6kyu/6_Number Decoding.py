def decode(n):
    r, n = [], str(n)
    for i, x in enumerate(n.split('98')):
        if i % 2: r.append(int(x, 2))
        else:
            t = ''
            for j in range(0, len(x), 3):
                t += chr(ord('a') + int(x[j:j + 3]) - 101)
            r.append(t)
    return ', '.join(str(x) for x in r if x)
    # Write your code here (feel free to delete this)
