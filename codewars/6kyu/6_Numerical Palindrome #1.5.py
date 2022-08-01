def palindrome(num,s):
    if not isinstance(num, int) or not isinstance(s, int) or num < 0 or s < 0:
        return "Not valid"
    r = []
    def check(x):
        x = str(x)
        return len(x) > 1 and x == x[::-1]
    while len(r) < s:
        if check(num):
            r.append(num)
        num += 1
    return r