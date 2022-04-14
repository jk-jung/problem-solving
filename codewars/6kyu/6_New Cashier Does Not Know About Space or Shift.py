menu = [
    'Burger',
    'Fries',
    'Chicken',
    'Pizza',
    'Sandwich',
    'Onionrings',
    'Milkshake',
    'Coke',
]
def get_order(s):
    r = []

    for x in menu:
        while x.lower() in s:
            r.append(x)
            s = s.replace(x.lower(), '', 1)

    return ' '.join(r)