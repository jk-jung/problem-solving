import json
from collections import Counter

def find_seventh_sons_of_seventh_sons(s):
    r = set()
    def f(v, ck=False):
        a, b = 0, 0
        for x in v['children']:
            if x['gender'] == 'male': a += 1
            else: b += 1

            if a == 7 and b == 0:
                f(x, True)
                if ck: r.add(x['name'])
            else:
                f(x, False)

    f(json.loads(s))
    return r