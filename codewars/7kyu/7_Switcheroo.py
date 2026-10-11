def switcheroo(s):
    return ''.join('a' if x == 'b' else ('b' if x == 'a' else 'c') for x in s)
