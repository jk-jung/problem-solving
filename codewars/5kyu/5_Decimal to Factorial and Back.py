def dec_2_fact_string(nb):
    x = 1
    for i in range(1, 37): x *= i

    r = ''
    for i in range(36, 0, -1):
        t = min(i, nb // x)
        nb -= t * x
        if t < 10:
            r += str(t)
        else:
            r += chr(ord('A') + t - 10)
        x //= i
    return r.lstrip('0') + '0'


def fact_string_2_dec(s):
    x = 1
    r = 0
    for i, k in enumerate(reversed(s)):
        try:
            k = int(k)
        except:
            k = ord(k) - ord('A') + 10
        r += x * int(k)
        x *= (i + 1)
    return r
