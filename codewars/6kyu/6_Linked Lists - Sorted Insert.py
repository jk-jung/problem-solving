def sorted_insert(head, x):
    if not head or head.data > x:
        return push(head, x)
    x = Node(x)
    h = head
    while h:
        if not h.next or h.next.data > x.data:
            x.next = h.next
            h.next = x
            break
        h = h.next
    return head