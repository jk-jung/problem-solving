from preloaded import LinkedList


def list_to_array(x: LinkedList) -> list:
    r = []
    while x:
        r.append(x.value)
        x = x.next
    return r
