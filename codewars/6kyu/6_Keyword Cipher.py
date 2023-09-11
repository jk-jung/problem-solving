def keyword_cipher(m, s):
    s = s + 'abcdefghijklmnopqrstuvwxyz'
    s = [x for i, x in enumerate(s) if s.find(x) == i]

    r = ''
    for x in m.lower():
        if x == ' ':r += ' '
        else: r += s[ord(x) - ord('a')]
    return r
