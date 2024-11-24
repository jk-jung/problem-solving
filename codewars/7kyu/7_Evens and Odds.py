def evens_and_odds(n):
    if n % 2 == 0:
        return bin(n)[2:]
    return hex(n)[2:]