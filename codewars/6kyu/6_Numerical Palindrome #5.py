def palindrome(n):
    if not isinstance(n, int) or n < 0: return "Not valid"
    if n < 10:return False
    n = str(n)
    return len([x for x in set(n) if n.count(x) % 2]) <= 1