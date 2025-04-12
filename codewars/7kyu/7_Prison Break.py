def freed_prisoners(prison):
    r = 0
    if not prison[0]:
        return r
    cur = True
    for x in prison:
        if x == cur:
            r += 1
            cur = not cur
    return r