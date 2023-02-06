def ipv4_to_binary(s):
    return  '.'.join(format(int(x), '08b') for x in s.split('.'))