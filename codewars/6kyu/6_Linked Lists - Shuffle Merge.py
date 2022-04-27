def shuffle_merge(a, b):
    r = Node()
    t = r
    while a or b:
        if a:
            r.next = a
            a = a.next
            r = r.next
        if b:
            r.next = b
            b = b.next
            r = r.next

    return t.next