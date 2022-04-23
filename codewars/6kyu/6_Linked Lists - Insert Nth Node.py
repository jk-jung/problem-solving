class Node(object):
    def __init__(self, data):
        self.data = data
        self.next = None

def insert_nth(h, i, d):
    if i == 0:
        r = Node(d)
        r.next = h
        return r
    hh = h
    i -= 1
    while i:
        i -= 1
        h = h.next
    t = h.next
    r = Node(d)
    h.next = r
    r.next = t
    return hh