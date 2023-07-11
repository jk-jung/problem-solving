from itertools import zip_longest

def sep_str(s):
    return list(map(list, zip_longest(*s.split(), fillvalue="")))
