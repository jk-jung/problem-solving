def direction_in_grid(n, m):
    if n <= m:
        return 'R' if n % 2 else 'L'
    else:
        return 'D' if m % 2 else 'U'
