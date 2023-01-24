from collections import Counter

class Checkout(object):
    def __init__(self, sales={}):
        self.total = .0
        self.prices = {
            'apple': 0.4,
            'orange': 0.75,
            'potato': 0.8,
            'onion': 0.99,
            'leek': 2.99,
            'tart': 5.00,
            'rice': 1.1,
            'carrot': 0.25,
            'celery': 1.2,

        }
        self.sales = sales
        self.count = Counter()

    def scan(self, x, cnt=1):
        self.count[x] += cnt
        self.total = 0
        for k, v in self.count.items():
            if k in self.sales:
                s = self.sales[k]
                if 'off' in s:
                    pr, cnt = s.replace('ormore',  '').split('off')
                    pr, cnt = float(pr), int(cnt)
                    if v >= cnt:
                        self.total -= pr
                elif 'buy' in s:
                    c1, c2 = [int(y) for y in s[3:].split('get')]
                    cc = 0
                    while v > 0:
                        cc += min(v, c1)
                        v -= (c1 + c2)
                    v = cc
                else:
                    cnt, pr = s.split('for')
                    cnt, pr = int(cnt), float(pr)
                    while v >= cnt:
                        v -= cnt
                        self.total += pr
            self.total += self.prices.get(k, .0) * v
