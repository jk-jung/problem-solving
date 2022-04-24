def insert_sort(x):
    r = []
    while x:
        r.append(x.data)
        x = x.next
    return build_nodes(sorted(r))