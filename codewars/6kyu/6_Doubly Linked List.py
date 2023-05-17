class Node(object):
    def __init__(self):
        pass


class DoublyLinkedList(object):
    def __init__(self):
        self.v = []
    def push(self, x):
        self.v.append(x)
    def pop(self):
        return self.v.pop(-1)
    def shift(self):
        return self.v.pop(0)
    def unshift(self, x):
        self.v = [x] + self.v
        