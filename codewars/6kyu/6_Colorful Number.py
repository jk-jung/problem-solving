def colorful(n):
    n = str(n)
    y = set()
    for i in range(len(n)):
        x = 1
        for j in range(i, len(n)):
            x *= int(n[j])
            if x in y: return False
            y.add(x)
    return True
