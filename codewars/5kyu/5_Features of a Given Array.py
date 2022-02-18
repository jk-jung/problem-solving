from collections import OrderedDict
class Array(object):
    def __init__(self, arr = []):
        self.v = arr

    def num_elements(self):
        return len(self.v)

    def num_values(self):
        return len(set(self.v))

    def start_end(self):
        return [self.v[0], self.v[-1]]

    def range_(self):
        t = sorted(self.v)
        return [t[0], t[-1]]

    def largest_increas_subseq(self):
        r, c = [], []
        for x in self.v:
            if len(c) == 0 or c[-1] < x:
                c.append(x)
                if len(c) > len(r): r = c
            else: c = [x]
        return r if len(r) >= 3 else 'No increasing subsequence'

    def largest_decreas_subseq(self):
        r, c = [], []
        for x in self.v:
            if len(c) == 0 or c[-1] > x:
                c.append(x)
                if len(c) > len(r): r = c
            else: c = [x]
        return r if len(r) >= 3 else 'No decreasing subsequence'

    def __str__(self):
        d = OrderedDict()
        d['1.number of elements'] = self.num_elements()
        d['2.number of different values'] = self.num_values()
        d['3.first and last terms'] = self.start_end()
        d['4.range of values'] = self.range_()
        d['5.increas subseq'] = self.largest_increas_subseq()
        d['6.decreas subseq'] = self.largest_decreas_subseq()

        return str(d)
