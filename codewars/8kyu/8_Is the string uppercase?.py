def is_uppercase(t):
    t = "".join([x for x in list(t) if x.isalpha()])
    return not t or t.isupper()
