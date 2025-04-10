def hex_hash(code):
    r = 0
    for x in code:
        for y in hex(ord(x))[2:]:
            if y.isdigit():
                r += int(y)
    return r