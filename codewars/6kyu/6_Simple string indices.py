def solve(s, i):
    if s[i] != '(': return -1
    cnt = 1
    while i - 1 < len(s):
        i += 1
        if s[i] == '(':
            cnt += 1
        if s[i] == ')':
            cnt -= 1
            if cnt == 0:
                return i
    return -1