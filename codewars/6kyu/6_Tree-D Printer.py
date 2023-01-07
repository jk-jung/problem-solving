# preloaded TreeNode class:
"""
class TreeNode:
    def __init__(self, value, children = None):
        self.value = value
        self.children = [] if children is None else children
"""
from preloaded import TreeNode

def tree_printer(tree : TreeNode) -> str:
    r = []
    def f(t, d=0):
        if len(r) <= d: r.append([])
        r[d].append(str(t.value))
        [f(x, d + 1) for x in t.children]
    f(tree)
    return '\n'.join(' '.join(x) for x in r)
