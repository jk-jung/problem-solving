def maximum_product_of_parts(n):
    s = str(n)
    r = 0
    for i in range(1, len(s)):
        for j in range(i + 1, len(s)):
            a = int(s[:i])
            b = int(s[i:j])
            c = int(s[j:])
            r = max(r, a * b * c)
    return r