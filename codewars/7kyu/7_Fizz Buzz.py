def fizzbuzz(n):
    def f(x):
        if x % 15 == 0:
            return 'FizzBuzz'
        if x % 3 == 0:
            return 'Fizz'
        if x % 5 == 0:
            return 'Buzz'
        return x
    return [f(x) for x in range(1, n + 1)]
