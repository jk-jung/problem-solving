class Node(object):
    def __init__(self, data):
        self.data = data
        self.next = None

def push(head, data):
    r = Node(data)
    r.next = head
    return r

def build_one_two_three():
    a = Node(1)
    b = Node(2)
    c = Node(3)
    a.next = b
    b.next = c
    return a