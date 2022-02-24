def flesch_kincaid(text):
    text = text.lower().replace('!', '.').replace('?', '.')
    wcnt = 0
    scnt = 0
    cnt = 0

    for t in text.split('.'):
        if not t: continue
        scnt += 1
        for w in t.strip().split(' '):
            w = ''.join(x for x in w if x.isalnum())
            wcnt += 1

            for i, v in enumerate(w):
                if v in 'aeiou':
                    if i == 0 or w[i-1] not in 'aeiou':
                        cnt += 1

    avg = wcnt / scnt
    avg2 = cnt / wcnt

    return round((0.39 * avg) + (11.8 * avg2) - 15.59, 2)