def dot(m,n):
    s = '---'.join('+' * (m + 1)) + '\n'
    p = ' o '.join('|' * (m + 1)) + '\n'
    return  p.join([s] * (n + 1)).strip()
