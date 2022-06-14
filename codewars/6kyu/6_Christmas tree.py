def christmas_tree(n):
    return '\n'.join(' ' * (n - i - 1) + '*' * (i * 2 + 1) + ' ' * (n - i - 1) for i in range(n))
