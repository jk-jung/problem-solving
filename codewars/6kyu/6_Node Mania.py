def search_k_from_end(linked_list, k):
    x = linked_list.head
    v = []
    while x:
        v.append(x.data)
        x = x.next
    return v[-k] if k <= len(v) else None
