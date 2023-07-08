def vowel_recognition(s):
    r = 0
    for i in range(len(s)):
        if s[i].lower() in 'aeiou':
            r += (i + 1) * (len(s) - i)
    return r
