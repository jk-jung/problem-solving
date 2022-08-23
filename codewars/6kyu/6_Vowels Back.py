def vowel_back(s):
    def f(x):
        if x == 'c': return 'b'
        if x == 'o': return 'n'
        if x == 'd': return 'a'
        if x == 'e': return 'a'
        if x in 'aeiou':
            y = chr((ord(x) - ord('a') + 21) % 26 + ord('a'))
        else:
            y = chr((ord(x) - ord('a') + 9) % 26 + ord('a'))
        if y in 'code': return x
        return y
    return ''.join(f(x) for x in s)