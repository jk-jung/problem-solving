def mutate_my_strings(s1,s2):
    r = [s1]
    t = list(s1)
    for i in range(len(s1)):
        if s1[i] == s2[i]:continue
        t[i] = s2[i]
        r.append(''.join(t))
    return '\n'.join(r) + '\n'
