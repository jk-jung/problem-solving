def pattern(n):
    m = n * 2 - 1
    r = []
    for i in range(n):
        s = [' ' for x in range(m)]
        s[i] = s[m -i - 1] = str(i + 1)[-1]
        r.append(''.join(s))
    return '\n'.join(r + r[:-1][::-1])
