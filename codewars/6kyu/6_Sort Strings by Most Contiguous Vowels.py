def sort_strings_by_vowels(s):
    def f(x):
        r, c = 0, 0
        for y in x[1].lower():
            if y in 'aeiou': c +=1
            else: c = 0
            r = max(r, c)
        return (-r, x[0])
    return [x[1] for x in sorted(enumerate(s), key=f)]
