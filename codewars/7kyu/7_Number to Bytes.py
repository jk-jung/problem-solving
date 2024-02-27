def to_bytes(n):
    n = bin(n)[2:][::-1]
    r = []
    for x in range(0, len(n), 8):
        r.append((n[x:x + 8] + '0'*8)[:8][::-1])
    return r[::-1]
