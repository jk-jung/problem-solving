def alphabet_war(s):
    v = [0, 0]
    cs = ['sbpw', 'zdqm']
    for i in range(len(s)):
        if i and s[i - 1] == '*': continue
        if i + 1 != len(s) and s[i + 1] == '*': continue
        for j in range(2):
            if s[i] in cs[j]:
                v[j] += cs[j].index(s[i]) + 1
    if v[0] == v[1]: return "Let's fight again!"
    return "Left side wins!" if v[0] > v[1] else "Right side wins!"
