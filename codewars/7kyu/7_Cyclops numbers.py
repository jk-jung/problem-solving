def cyclops(n):
    s = bin(n)[2:].split('0')
    return len(s) == 2 and len(s[0]) == len(s[1])
