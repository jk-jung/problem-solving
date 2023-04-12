from preloaded import adapt_size, display

adapt_size(0.9)     # You can adjust the size of the cells, so that your heart is displayed better
# display(heart)    # To see your (he)art


def draw(n):
    m = n // 2 - 2
    s = '◢' + '■' * m + '◣◢' + '■' * m + '◣'
    s += '\n' + '\n'.join(['■' * n for i in range(n // 6)]) + '\n'
    for i in range(n // 2):
        s += ' ' * i + '◥' + '■' * (n - 2 - i * 2)  + '◤' + ' ' * i+ '\n'
    return s[:-1]
