class Node(object):
    def __init__(self, data=None):
        self.data = data
        self.next = None

def sorted_merge(*x):
    r, x = [], list(x)
    while any(x):
        i = 0 if not x[1] or (x[0] and x[0].data < x[1].data) else 1
        r.append(x[i].data)
        x[i] = x[i].next
    return build_list(r)