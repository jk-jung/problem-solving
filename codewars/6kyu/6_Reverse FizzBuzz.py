def reverse_fizzbuzz(s):
    v = s.split(' ')
    if any(x.isdigit() for x in v):
        for i, x in enumerate(v):
            if x.isdigit():
                return [int(x) - i + j for j in range(len(v))]

    if v == ['Fizz']: return [3]
    if v == ['Buzz']: return [5]
    if v == ['FizzBuzz']: return [15]
    if v == ['Fizz', 'Buzz']: return [9, 10]
    if v == ['Buzz', 'Fizz']: return [5, 6]
