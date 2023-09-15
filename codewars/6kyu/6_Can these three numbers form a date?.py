from datetime import date
def f(x, y, z):
    try:
        return date(1900 + x, y, z)
    except:
        return None
def unique_date(x, y, z):
    v = [
        f(x, y, z),
        f(x, z, y),
        f(y, x, z),
        f(y, z, x),
        f(z, x, y),
        f(z, y, x),
    ]
    a = {x for x in v if x}
    if len(a) >= 2: return 'ambiguous'
    if len(a) == 0: return 'invalid'
    return str(list(a)[0]).replace('-', '/')[2:]
