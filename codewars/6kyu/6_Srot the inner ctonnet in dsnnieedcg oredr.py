def sort_the_inner_content(words):
    def f(x):
        if len(x) <= 2: return x
        return x[0] + ''.join(sorted(x[1:-1], reverse=True)) + x[-1]
    return ' '.join(f(x) for x in words.split(' '))