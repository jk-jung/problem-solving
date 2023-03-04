def reverse_fizz_buzz(a):
    def f(k): return a.index(k) if k in a else 1 << 30
    return (min(f('Fizz'), f('FizzBuzz')) + 1, min(f('Buzz'), f('FizzBuzz')) + 1)
