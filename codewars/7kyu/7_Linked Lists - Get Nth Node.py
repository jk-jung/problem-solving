class Node(object):
    def __init__(self, data):
        self.data = data
        self.next = None

def get_nth(node, x):
    if x < 0: raise "!"
    try:
        node.next
    except:
        raise "!"
    while x:
        node = node.next
        if not node: raise "!"
        x -= 1
    return node