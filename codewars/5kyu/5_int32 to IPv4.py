def int32_to_ip(x):
    r = []
    for _ in range(4):
        r.append(str(x % 256))
        x //= 256

    return '.'.join(reversed(r))
