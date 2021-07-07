def make(s, x, y):
    if x < y: s = s[:x] + s[x+1:y+1] + s[x] + s[y+1:]
    else: s = s[:y] + s[x] + s[y:x] + s[x+1:]
    return [int(s), x, y]


def smallest(n):
    s = str(n)
    r = []
    for i in range(len(s)):
        for j in range(len(s)):
            r.append(make(s, i, j))
    return sorted(r)[0]