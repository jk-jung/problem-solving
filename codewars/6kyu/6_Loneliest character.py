def loneliest(s):
    r = []
    s = s.strip()
    for i, x in enumerate(s):
        if x != ' ':
            t = 0
            for j in range(i - 1, -1, -1):
                if s[j] == ' ': t += 1
                else: break
            for j in range(i + 1, len(s)):
                if s[j] == ' ': t += 1
                else: break
            r.append((t, x))
    m = max(r)[0]
    return [x[1] for x in r if x[0] == m]
