def diamonds_and_toads(sentence,f):
    r = {'ruby': 0, 'crystal': 0} if f == 'good' else {'python': 0, 'squirrel': 0}
    for x in sentence:
        for k in r:
            if x == k[0]: r[k] += 1
            elif x.lower() == k[0]: r[k] += 2
    return r