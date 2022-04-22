class Node(object):
    def __init__(self, data=None):
        self.data = data
        self.next = None

def sorted_intersect(a, b):
    def f(x):
        s = set()
        while x:
            s.add(x.data)
            x = x.next
        return s
    r = sorted(f(a) & f(b))
    return build_list(r)