def split_without_loss(s, t):
    r = s.split(t.replace('|', ''))
    for i in range(1, len(r)):
        r[i - 1] += t.split('|')[0]
        r[i] = t.split('|')[1] + r[i]
    return [x for x in r if x]
