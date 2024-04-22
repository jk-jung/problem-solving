def ascii_encrypt(a):
    return ''.join(chr(ord(x) + i) for i, x in enumerate(a))

    
def ascii_decrypt(a):
    return ''.join(chr(ord(x) - i) for i, x in enumerate(a))
