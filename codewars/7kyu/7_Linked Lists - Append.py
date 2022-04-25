class Node(object):
    def __init__(self, data):
        self.data = data
        self.next = None

def append(a, b):
    if a is None:
        return b
    c = a
    while c.next:
        c = c.next
    c.next = b
    return a