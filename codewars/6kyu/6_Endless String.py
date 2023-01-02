def endless_string(s, a, b) -> str:
    if b < 0: a, b = a + b + 1, -b
    return (s[a % len(s):] + s * b)[:b]