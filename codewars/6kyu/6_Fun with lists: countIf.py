def count_if(head, func):
    r = 0
    while head:
        if func(head.data): r += 1
        head = head.next
    return r