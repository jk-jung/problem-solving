def binary_to_string(b):
    return ''.join(chr(int(b[i:i + 8], 2)) for i in range(0, len(b), 8))
