def tree_amplitude(a):
    def dfs(x, s, e):
        s = min(s, x.data)
        e = max(e, x.data)
        if not x.left and not x.right:
            return e - s
        else:
            r = 0
            if x.left: r = max(r, dfs(x.left, s, e))
            if x.right: r = max(r, dfs(x.right, s, e))
            return r
    return dfs(a, a.data, a.data) if a else 0
