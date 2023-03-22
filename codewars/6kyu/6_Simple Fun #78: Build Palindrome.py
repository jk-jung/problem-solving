def build_palindrome(s):
    for i in range(len(s)):
        t = s + s[:i][::-1]
        if t == t[::-1]: return t