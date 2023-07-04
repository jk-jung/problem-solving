def replace_letters(w):
    def f(x):
        i = alphabet.index(x)
        d = -1 if x in vowels else 1
        while (alphabet[i] in vowels) == (x in vowels):
            i = (i + d + 26) % 26
        return alphabet[i]
    return ''.join(map(f, w))
