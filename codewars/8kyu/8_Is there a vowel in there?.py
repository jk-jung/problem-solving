def is_vow(a):
    return [chr(x) if chr(x) in 'aeiou' else x for x in a]