def build_row_text(index, character):
    a = list(' '.join('|' * 10))
    a[index * 2 + 1] = character
    return ''.join(a)
