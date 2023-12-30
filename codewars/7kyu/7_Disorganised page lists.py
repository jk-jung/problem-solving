def find_page_number(v):
    r = []
    j = 1
    for i in v:
        if i == j:j += 1
        else: r.append(i)
    return r
