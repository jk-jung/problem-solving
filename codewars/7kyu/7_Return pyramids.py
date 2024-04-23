def pyramid(n):
    r = []
    for i in range(n - 1):
        r.append(' ' * (n - i - 1) + '/' + ' ' * (i * 2) + '\\')
    r.append(f"/{'_' * (n * 2 - 2)}\\")
    return '\n'.join(r) + '\n'