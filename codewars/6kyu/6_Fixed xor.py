def fixed_xor(a, b):
    return ''.join(hex(int(x,16)^int(y,16))[2:] for x,y in zip(a,b))
