def binary_to_string(s):
    return ''.join(chr(int(x, 2)) for x in s.split('0b') if x)
