def swap(st):
    return ''.join(x.upper() if x in 'aeiou' else x for x in st)
