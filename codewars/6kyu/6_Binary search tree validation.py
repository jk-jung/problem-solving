class T:
    def __init__(self,value,left=None,right=None):
        self.value=value
        self.left=left
        self.right=right

def f(x):
    r = []
    if not x: return r
    if x.left: r.extend(f(x.left))
    r.append(x.value)
    if x.right: r.extend(f(x.right))
    return r

def is_bst(node):
    t = f(node)
    return t == sorted(t) or t == sorted(t)[::-1]