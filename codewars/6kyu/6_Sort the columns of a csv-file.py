def sort_csv_columns(c):
    t = sorted(zip(*[x.split(';') for x in c.split('\n')]), key=lambda x: x[0].lower())
    return '\n'.join([';'.join(x) for x in zip(*t)])
