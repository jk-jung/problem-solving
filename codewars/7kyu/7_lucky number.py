def is_lucky(n):
    return sum(map(int, str(n))) % 9 == 0
