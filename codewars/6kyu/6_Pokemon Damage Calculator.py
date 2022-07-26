t = {('grass', 'fire'),
     ('fire', 'water'),
     ('water', 'grass'),
     ('water', 'electric')}

def calculate_damage(t1, t2, a, d):
    if (t2, t1) in t: e = 2
    elif t1 == t2 or (t1, t2) in t: e = .5
    else: e = 1
    return 50 * a / d * e
