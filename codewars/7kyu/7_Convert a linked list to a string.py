def stringify(node):
    r = []
    while node:
        r.append(node.data)
        node = node.next
    r.append(node)
    return ' -> '.join(map(str, r))