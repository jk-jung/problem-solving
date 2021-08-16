def valid_ISBN10(s):
    if len(s) != 10: return False
    try:
        r = 0
        for i in range(9):
            r = (r + int(s[i]) * (i + 1)) % 11
        print(r)
        r = 'X' if r == 10 else str(r)
        return r == s[-1]
    except:
        return False