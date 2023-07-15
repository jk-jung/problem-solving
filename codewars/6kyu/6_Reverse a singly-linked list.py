def reverse_list(v):
    t = []
    while v:
        t.append(v.value)
        v = v.next
    return make_linked_list(t[::-1])
