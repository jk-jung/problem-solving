""" For your information:
class Node(object):
    def __init__(self, data=None):
        self.data = data
        self.next = None
"""

def front_back_split(s, front, back):
    v, i = [], 0
    f = front
    while s != None:
        v.append(s)
        s = s.next

    n = len(v)
    m = (n + 1) // 2
    assert n >=2

    def assign(n, t):
        for i, x in enumerate(t):
            n.data = x.data
            if i + 1 != len(t): n.next = t[i + 1]
            else: n.next = None
            n = n.next
    assign(front, v[:m])
    assign(back, v[m:])