def number_joy(n):
    t = sum(map(int, str(n)))
    return n % t == 0 and t * int(str(t)[::-1]) == n
