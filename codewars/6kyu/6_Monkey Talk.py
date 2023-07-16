def monkey_talk(v):
    def f(x):
        if x[0] in 'aeiou': return 'e'
        return 'o'
    return (' '.join(f(x.lower()) * 2 + 'k' for x in v.split(' ')) + '.').capitalize()
