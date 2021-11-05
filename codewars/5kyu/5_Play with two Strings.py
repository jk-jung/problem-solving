def change(s, y):
    f = lambda k: k.lower() if k.upper() == k else k.upper()
    return ''.join(x if x.upper() != y.upper() else f(x) for x in s)

def work_on_strings(a,b):
    for x in a:
        b = change(b, x)
    for x in b:
        a = change(a, x)
    return a + b