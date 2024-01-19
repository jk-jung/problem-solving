def sum_digits(n):
    return sum(ord(x) - ord('0') for x in str(abs(n)))
