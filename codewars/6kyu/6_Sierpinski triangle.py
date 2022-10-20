def sierpinski(n):
    if n == 1: return ' * \n* *'
    s = sierpinski(n - 1).split('\n')
    m = (1 << (n - 1))
    for i in range(len(s)):
        s.append(s[i] + ' ' + s[i])
        s[i] = ' ' * m + s[i] + ' ' * m
    return '\n'.join(s)
