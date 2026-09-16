enc = bytes.maketrans(b"RGB", b"\x00\x01\x02")
dec = bytes.maketrans(b"\x00\x01\x02", b"RGB")
mod = bytes.maketrans(b"\x00\x01\x02\x03\x04", b"\x00\x02\x01\x00\x02")


def f(n):
    r, b = [], 1
    while n:
        while n % 3:
            n -= 1
            r.append(b)
        n //= 3
        b *= 3
    return r[::-1]


def cnt(n):
    c = 1
    while n:
        c *= (n % 3) + 1
        n //= 3
    return c


def calc(s):
    n = len(s)
    pos, cof, p, m = [0], [1], 1, n - 1
    while m:
        d = m % 3
        if d:
            w = (1, 1) if d == 1 else (1, 2, 1)
            step = [j * p for j in range(d + 1)]
            pos = [o + t for o in pos for t in step]
            cof = [c * w[j] % 3 for c in cof for j in range(d + 1)]
        m //= 3
        p *= 3

    V = {'R': 0, 'G': 1, 'B': 2}
    tot = sum(c * V[s[o]] for o, c in zip(pos, cof)) % 3
    if (n - 1) & 1:
        tot = -tot % 3
    return 'RGB'[tot]


def triangle(s):
    n = len(s) - 1
    if cnt(n) < 1000000:
        return calc(s)

    s = bytes(s, "latin-1").translate(enc)

    for i, x in enumerate(f(n)):
        m = len(s) - x
        a = int.from_bytes(s[:m], "big")
        b = int.from_bytes(s[-m:], "big")
        s = (a + b).to_bytes(m, "big").translate(mod)

    return s.translate(dec).decode()
