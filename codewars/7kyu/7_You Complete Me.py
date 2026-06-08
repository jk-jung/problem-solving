def complete(a):
    for i in range(1, len(a) + 1):
        b = a + a[:i][::-1]
        if b.endswith(a[::-1]):
            return b
