def filter_list(l):
    r = []
    for x in l:
        try:
            if x >= 0:
                r.append(x)
        except:
            pass
    return r