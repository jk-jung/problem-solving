def loop_size(node):
    c = {}
    for i in range(100000):
        if node in c: return i - c[node]
        c[node] = i
        node = node.next
