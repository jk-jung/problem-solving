def palindrome(n):
    try:
        if n < 0: return "Not valid"
        for i in range(1000):
            x = str(n + i)
            if len(x) >= 2 and x == x[::-1]: return int(x)
            x = str(n - i)
            if len(x) >= 2 and x == x[::-1]: return int(x)
    except:
        return "Not valid"
