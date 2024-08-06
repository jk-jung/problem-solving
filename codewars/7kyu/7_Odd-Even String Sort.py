def sort_my_string(s):
    a = ''.join([x for i, x in enumerate(s) if i % 2 == 0])
    b = ''.join([x for i, x in enumerate(s) if i % 2 == 1])
    return a + ' ' + b