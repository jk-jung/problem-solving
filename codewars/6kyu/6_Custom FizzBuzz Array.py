def fizz_buzz_custom(a='Fizz', b='Buzz', n1=3, n2=5):
    def f(x):
        r = ''
        if x % n1 == 0:
            r += a
        if x % n2 == 0:
            r += b
        return r if r else x
    return [f(x) for x in range(1, 101)]
