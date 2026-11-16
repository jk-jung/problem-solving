def sc(n):
    s = bin(n)[2:]
    print(s)
    r = set()
    for i in range(len(s)):
        for j in range(i, len(s)):
            a = int(s[i:j + 1], 2)
            if a and n % a == 0:
                r.add(a)
    return sorted(list(r))