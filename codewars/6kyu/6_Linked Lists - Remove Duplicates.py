class Node(object):
    def __init__(self, data):
        self.data = data
        self.next = None

def remove_duplicates(x):
    r = x
    while x:
        y = x
        while x and x.data == y.data:
            x = x.next
        y.next = x
    return r