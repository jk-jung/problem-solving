def square_digits_sequence(n):
    s = set()
    while n not in s:
        s.add(n)
        n = sum(int(x) ** 2 for x in str(n))
    return len(s) + 1