def increment_string(s):
    n = len(s)
    k = n
    for i in range(n - 1, -1, -1):
        if s[i] not in '0123456789':
            break
        k = i

    if k == n: return s + '1'
    v = s[k:]
    vs = str(int(v) + 1)
    while len(vs) < len(v): vs = '0' + vs

    return s[:k] + vs
