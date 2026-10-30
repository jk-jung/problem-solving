def palindrome_chain_length(n):
    r = 0 
    while str(n) != str(n)[::-1]:
        n += int(str(n)[::-1])
        r += 1
    return r
