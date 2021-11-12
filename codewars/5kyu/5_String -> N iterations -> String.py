def jumbled_string(s, n):
    r = [s]
    for _ in range(n):
        s = s[0::2] + s[1::2]
        if r[0] == s:
            return r[n % len(r)]
        r.append(s)
    return s