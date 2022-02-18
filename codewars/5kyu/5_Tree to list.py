class Node:
    def __init__(self, data, child_nodes=None):
        self.data = data
        self.child_nodes = child_nodes

def tree_to_list(tree_root):
    r = [tree_root.data]
    def dfs(x):
        if x.child_nodes:
            [r.append(y.data) for y in x.child_nodes]
            [dfs(y) for y in x.child_nodes]

    dfs(tree_root)
    return r