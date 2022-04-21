class Node(object):
    def __init__(self, data=None):
        self.data = data
        self.next = None

def reverse(n):
    y = Node()
    z = y
    def _f(x):
        if not x: return
        _f(x.next)
        nonlocal z
        z.next = Node(x.data)
        z = z.next
    _f(n)
    return y.next