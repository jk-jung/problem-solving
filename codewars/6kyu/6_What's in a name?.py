def name_in_str(a, b):
    a, b = a.lower(), b.lower()
    i = 0
    for x in b:
        while i < len(a):
            if a[i] == x:
                break
            i += 1
        if i == len(a):
            return False
        i += 1
    return True
