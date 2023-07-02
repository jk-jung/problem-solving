def find_the_key(a, b):
    v = ''.join(map(str, [y - ord(x) + ord('a') - 1 for x, y in zip(a, b)]))
    for i in range(1, len(v)):
        if v in v[:i] * 1000:
            return int(v[:i])
        