class Node(object):
    def __init__(self, data=None):
        self.data = data
        self.next = None

def merge_sort(x):
    r = []
    while x:
        r.append(x.data)
        x = x.next
    return build_list(sorted(r))