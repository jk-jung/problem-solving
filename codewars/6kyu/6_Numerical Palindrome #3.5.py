def palindrome(n):
    if not isinstance(n, int) or n < 0: return "Not valid"
    n = str(n)
    r = []
    for i in range(len(n)):
        for j in range(i + 1, len(n)):
            s = n[i:j + 1]
            if int(s) == int(s[::-1]) and str(int(s)) == s:
                r.append(int(s))
    if not r: return  'No palindromes found'
    return sorted(set(r))
