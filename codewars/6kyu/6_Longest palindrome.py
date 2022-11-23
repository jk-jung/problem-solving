from collections import Counter

def longest_palindrome(s):
    s = Counter([x for x in s.lower() if x.isalnum()]).values()
    return sum(x - x % 2 for x in s) + any(x % 2 for x in s)
