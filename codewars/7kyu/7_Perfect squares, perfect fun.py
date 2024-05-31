def square_it(s):
    s = str(s)
    t = int(len(s) ** .5)
    if t ** 2 == len(s):
        return '\n'.join([s[i:i+t] for i in range(0, len(s), t)])
    return 'Not a perfect square!'