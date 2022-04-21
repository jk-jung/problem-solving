class Node(object):
    def __init__(self, data=None):
        self.data = data
        self.next = None

def reverse(y):
    r = []
    x = y
    while x:
        r.append(x.data)
        x = x.next
    x = y

    for i in reversed(r):
        x.data = i
        x = x.next
