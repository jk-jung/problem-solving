def char_to_ascii(s):
    r = {x: ord(x) for x in s if x.isalpha()}
    if r: return r
