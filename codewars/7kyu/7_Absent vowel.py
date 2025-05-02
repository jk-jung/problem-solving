def absent_vowel(x):
    for i, y in enumerate('aeiou'):
        if y not in x:
            return i