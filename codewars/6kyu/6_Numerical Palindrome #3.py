def palindrome(num):
    if not isinstance(num ,int) or num < 0: return "Not valid"
    n = str(num)
    r = 0
    for i in range(len(n)):
        for j in range(i, len(n)):
            a = n[i:j + 1]
            if len(a) > 1 and a == a[::-1]:
                r += 1
    return r
