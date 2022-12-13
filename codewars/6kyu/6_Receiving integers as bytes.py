def interpret_as_int32(s):
    s = b''.join(s)
    r = []
    for i in range(0, len(s), 4):
        x = s[i:i + 4]
        if len(x) == 4:
            r.append(int.from_bytes(x, byteorder='big', signed=True))
    return r
