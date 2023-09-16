import re
def testit(a):
    t = [
        {
            'm': 1,
            'km': 1000,
            'cm': 0.01,
            'dm': 0.1,
            'mm': 0.001,
        },
        {
            'm': 1,
            's': 1 / 60,
            'ms': 1 / 60 / 1000,
            'h': 1 * 60,
            'd': 1 * 60 * 24,
        }
    ]
    for k in t:
        ok = True
        v = []
        for x in a:
            m = re.match(r'(\d+)(.*)', x)
            if m[2] not in k:
                ok = False
                break
            v.append(float(m[1]) * k[m[2]])

        if ok:
            return [x[1] for x in sorted(enumerate(a),key=lambda x: v[x[0]])]

    return
