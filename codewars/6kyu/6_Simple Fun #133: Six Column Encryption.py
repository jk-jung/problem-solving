def six_column_encryption(s):
    r, n = '', len(s)
    for i in range(6):
        for j in range(i, (n + 5) // 6 * 6, 6):
            r += '.' if j >= n or s[j] == ' ' else s[j]
        r += ' '
    return r[:-1]
