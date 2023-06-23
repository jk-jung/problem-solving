def build_palindrome(a):
    for i in range(len(a)):
        b = a + a[::-1][len(a)-i:]
        c = a[::-1][:i] + a
        if b == b[::-1]: return b
        if c == c[::-1]: return c
