def heggeleggleggo(word):
    r = ''
    for x in word:
        r += x
        if x.isalpha() and x.lower() not in 'aeiou':
            r += 'egg'
    return r
