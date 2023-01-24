def find_additive_numbers(s):
    n = len(s)
    for i in range(1, n):
        for j in range(i + 1, n):
            x = s[:i]
            y = s[i:j]
            if len(x) != len(str(int(x))): continue
            if len(y) != len(str(int(y))): continue

            t = x + y
            r = [x, y]
            while len(t) < len(s):
                z = str(int(x) + int(y))
                t += z
                x, y = y, z
                r.append(z)
            if s == t: return r
    return []
