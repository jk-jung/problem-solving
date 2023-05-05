def palindrome(n):
    if not isinstance(n, int) or n < 0: return "Not valid"
    n = str(n)
    for x in '0123456789':
        if n.find(x + x) != -1: return True
        for y in '0123456789':
            if n.find(x + y + x) != -1: return True
    return False