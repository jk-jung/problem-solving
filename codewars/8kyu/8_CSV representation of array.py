def to_csv_text(a):
    return '\n'.join(','.join(map(str, x)) for x in a)
