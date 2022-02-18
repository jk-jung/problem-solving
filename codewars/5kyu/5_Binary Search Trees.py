class Tree(object):

    def __init__(self, root, left=None, right=None):
        assert root and type(root) == Node
        if left: assert type(left) == Tree and left.root < root
        if right: assert type(right) == Tree and root < right.root

        self.left = left
        self.root = root
        self.right = right

    def is_leaf(self):
        return not(self.left or self.right)


    def __str__(self):
        if self.is_leaf(): return f'[{self.root}]'
        l = str(self.left) if self.left else '_'
        r = str(self.right) if self.right else '_'
        return f'[{l} {self.root} {r}]'


    def __eq__(self, o):
        if not isinstance(o, Tree): return False
        return self.root == o.root and self.left == o.left and self.right == o.right

    def __ne__(self, other):
        return not (self == other)


class Node(object):

    def __init__(self, value, weight=1):
        self.value = value
        self.weight = weight

    def __str__(self):
        return str(self.value)

    def __lt__(self, other):
        return self.value < other.value

    def __gt__(self, other):
        return self.value > other.value

    def __eq__(self, other):
        return self.value == other.value

    def __ne__(self, other):
        return self.value != other.value
