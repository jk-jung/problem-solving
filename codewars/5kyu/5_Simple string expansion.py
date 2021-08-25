def solve(s):
    r = ''
    n = len(s)
    i = 0
    while i < n:
        x = s[i]
        if x.isdigit():
            cnt = 1
            i += 2
            t = '('
            while cnt > 0:
                t += s[i]
                if s[i] == '(': cnt += 1
                if s[i] == ')': cnt -= 1
                i += 1
            r += int(x) * solve(t)
        elif x.isalpha():
            r += x
            i += 1
        else:
            i += 1
    return r
