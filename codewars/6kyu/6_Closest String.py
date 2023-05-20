def hamming_distance(str1,str2):
    l = 0
    for i in range(0,len(str2)):
        if str1[i]!= str2[i]:
            l+=1
    return l

def closest_string(v):
    t = list(zip(*v))
    r = 'a' * len(t)
    def f(i=0, s=''):
        nonlocal r
        if i == len(t):
            a = max(hamming_distance(s, x) for x in v)
            b = max(hamming_distance(r, x) for x in v)
            if a < b: r = s
        else:
            [f(i + 1, s + x) for x in set(t[i])]
    f(0)
    return r