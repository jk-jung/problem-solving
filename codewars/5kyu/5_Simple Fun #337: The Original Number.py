num = [
    ['FOUR', 'U', '4'],
    ['TWO', 'W', '2'],
    ['SIX', 'X', '6'],
    ['ZERO', 'Z', '0'],
    ['FIVE', 'F', '5'],
    ['SEVEN', 'V', '7'],
    ['ONE', 'O', '1'],
    ['THREE', 'R', '3'],
    ['NINE', 'N', '9'],
    ['EIGHT', 'E', '8'],
]

def original_number(s):
    r = ''
    for n, c, k in num:
        while c in s:
            r += k
            for x in n:
                s = s.replace(x, '', 1)
    return ''.join(sorted(r))