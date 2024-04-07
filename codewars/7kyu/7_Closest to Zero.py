def closest(lst):
    lst = list(set(lst))
    lst.sort(key=lambda x: abs(x))
    if len(lst) > 1 and abs(lst[0]) == abs(lst[1]): return None
    return lst[0]
