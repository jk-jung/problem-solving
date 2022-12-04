from collections import Counter
def sorted_brands(v):
    ck = {}
    for i, x in enumerate(v):
        if x['brand'] not in ck:
            ck[x['brand']] = i
    c = Counter(x['brand'] for x in v)
    return [x[0] for x in sorted(c.items(), key=lambda x: (-x[1], ck[x[0]]))]
