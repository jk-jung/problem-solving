def linked_list_from_string(s):
    t = s.split(' -> ')
    y = None
    r = []
    for x in t:
        if x == 'None': break
        x = Node(int(x))
        if y:y.next = x
        y = x
        r.append(y)

    return None if not r else r[0]