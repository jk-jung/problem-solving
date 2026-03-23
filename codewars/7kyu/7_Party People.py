def party_people(a):
    a.sort()
    while a and a[-1] > len(a):
        a.pop()
    return len(a)
