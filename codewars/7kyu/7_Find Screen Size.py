def find_screen_height(a, b):
    x, y = map(int, b.split(':'))
    return f'{a}x{a * y // x}'