def get_column_title(a='a'):
    if not isinstance(a, int): raise Exception('Invalid type value should throw error.')
    if a <= 0: raise Exception('Invalid type value should throw error.')
    a -= 1
    b = 26
    c = 1
    while a > b:
        a -= b
        b *= 26
        c += 1
    r = ''
    for i in range(c):
        r += chr(a % 26 + ord('A'))
        a //= 26
    return r[::-1]
