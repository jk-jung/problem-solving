def capitalize(s, k):
    return ''.join([x.upper() if i in k else x for i, x in enumerate(s)])