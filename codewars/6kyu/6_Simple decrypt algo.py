from string import ascii_lowercase


def decrypt(s):
    return ''.join(str(s.count(i)) for i in ascii_lowercase)
