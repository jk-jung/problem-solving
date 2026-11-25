t = {"accounts": 1,
"finance": 2,
"canteen": 10,
"regulation": 3,
"trading": 6,
"change": 6,
"IS": 8,
"retail": 5,
"cleaning": 4,
"pissing about": 25}
def boredom(a):
    s = sum([t[x] for x in a.values()])
    if s <= 80:
        return 'kill me now'
    if s < 100:
        return 'i can handle this'
    return 'party time!!'