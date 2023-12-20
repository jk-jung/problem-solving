def box(n):
    return [
        '-' * n if i == 0 or i == n -1 else '-' + ' ' * (n - 2) + '-'
        for i in range(n)
    ]
