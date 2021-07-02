def insert(node, phone, i, tri):
    if len(phone) == i: return

    x = phone[i]
    if x not in node:
        node[x] = {}
        tri['size'] += 1
    insert(node[x], phone, i + 1, tri)


def phone_number(phone_numbers):
    tri = {'size': [0]}
    for phone in phone_numbers:
        insert(tri, phone, 0, tri)
    return tri['size']
