a = {
    0: '',
    1: 'one',
    2: 'two',
    3: 'three',
    4: 'four',
    5: 'five',
    6: 'six',
    7: 'seven',
    8: 'eight',
    9: 'nine',
    10: 'ten',
    11: 'eleven',
    12: 'twelve',
    13: 'thirteen',
    14: 'fourteen',
    15: 'fifteen',
    16: 'sixteen',
    17: 'seventeen',
    18: 'eighteen',
    19: 'nineteen',
    20: 'twenty',
    30: 'thirty',
    40: 'forty',
    50: 'fifty',
    60: 'sixty',
    70: 'seventy',
    80: 'eighty',
    90: 'ninety',
    100: 'hundred',

}
def wordify(n):
    r = []
    if n >= 100:
        r.append(a[n // 100])
        r.append(a[100])
        n %= 100
    if n in a:
        r.append(a[n])
    else:
        r.append(a[n // 10 * 10])
        r.append(a[n % 10])

    return ' '.join([x for x in r if x])
