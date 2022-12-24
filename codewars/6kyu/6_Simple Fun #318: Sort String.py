def sort_string(s):
    t = sorted([x for x in enumerate(s) if x[1].isalpha()], key=lambda x: (x[1].lower(), x[0]))
    return ''.join(t.pop(0)[1] if x.isalpha() else x for x in s)
