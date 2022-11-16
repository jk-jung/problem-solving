def numbers_of_letters(n):
    t = {
        '1': 'one',
        '2': 'two',
        '3': 'three',
        '4': 'four',
        '5': 'five',
        '6': 'six',
        '7': 'seven',
        '8': 'eight',
        '9': 'nine',
        '0': 'zero'
    }
    def f(s):
        return ''.join(t[x] for x in str(s))
    r = []
    while True:
        n = f(n)
        r.append(n)
        if n == 'four':break
        n = len(n)
    return r
