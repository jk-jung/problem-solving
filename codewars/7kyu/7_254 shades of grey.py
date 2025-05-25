def shades_of_grey(n):
    def f(x):
        return f'{hex(x + 1)[2:]:>02}'
    return [f'#{f(i)}{f(i)}{f(i)}' for i in range(n)[:254]]
