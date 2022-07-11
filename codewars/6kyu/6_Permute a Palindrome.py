from collections import Counter

def permute_a_palindrome (s):
    c = 0
    for x in Counter(s).values():
        if x % 2 == 1:
            c += 1
    return c <= 1