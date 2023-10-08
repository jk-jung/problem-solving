from itertools import zip_longest
def addition_without_carrying(a,b):
    r = ''
    for x, y in zip_longest(str(a)[::-1], str(b)[::-1]):
        x = x or '0'
        y = y or '0'
        x = ord(x) - ord('0')
        y = ord(y) - ord('0')
        r += str((x + y) % 10)
    return int(r[::-1])
