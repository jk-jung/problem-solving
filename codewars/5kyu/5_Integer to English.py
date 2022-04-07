t = [
    '',
    'thousand',
    'million',
    'billion',
    'trillion',
    'quadrillion',
    'quintillion',
    'sextillion',
    'septillion',
]

def f(x):
    d = { 1 : 'one', 2 : 'two', 3 : 'three', 4 : 'four', 5 : 'five',
          6 : 'six', 7 : 'seven', 8 : 'eight', 9 : 'nine', 10 : 'ten',
          11 : 'eleven', 12 : 'twelve', 13 : 'thirteen', 14 : 'fourteen',
          15 : 'fifteen', 16 : 'sixteen', 17 : 'seventeen', 18 : 'eighteen',
          19 : 'nineteen', 20 : 'twenty',
          30 : 'thirty', 40 : 'forty', 50 : 'fifty', 60 : 'sixty',
          70 : 'seventy', 80 : 'eighty', 90 : 'ninety' }

    s = []
    for k, v in reversed(d.items()):
        if x >= k:
            x -= k
            s.append(v)
    return ' '.join(s)

def int_to_english(n):
    r = []
    for s in t:
        x = n % 1000
        n //= 1000

        if not x: continue
        rr = []
        if x // 100:
            rr.append(f(x // 100))
            rr.append('hundred')
        if x % 100:
            rr.append(f(x % 100))
        if s: rr.append(s)
        r = rr + r

    return ' '.join(r)