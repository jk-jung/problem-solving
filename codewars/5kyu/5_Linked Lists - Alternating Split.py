class Node(object):
    def __init__(self, data=None):
        self.data = data
        self.next = None

class Context(object):
    def __init__(self, first, second):
        self.first = first
        self.second = second

def alternating_split(head):
    a = [Node(), Node()]
    b = [None, None]
    st = 0

    cnt = 0
    while head:
        cnt += 1
        print(head.data, st, a)
        a[st].next = Node(head.data)
        if b[st] is None: b[st] = a[st].next
        head = head.next
        a[st] = a[st].next
        st ^= 1

    assert cnt >= 2
    return Context(*b)