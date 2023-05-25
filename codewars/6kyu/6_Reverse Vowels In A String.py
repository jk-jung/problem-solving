def reverse_vowels(s):
    s = list(s)
    a, b = 0, len(s) - 1
    while a <= b:
        while a < len(s) and s[a].lower() not in 'aeiou': a += 1
        while b >= 0 and s[b].lower() not in 'aeiou': b -= 1
        if a <= b: s[a], s[b] = s[b], s[a]
        a += 1
        b -= 1
    return ''.join(s)