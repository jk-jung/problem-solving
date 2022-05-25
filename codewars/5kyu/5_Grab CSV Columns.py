def csv_columns(csv, indices):
    r = []
    for rows in csv.split('\n'):
        t = []
        for i, x in enumerate(rows.split(',')):
            if i in indices:
                t.append(str(x))
        r.append(t)
    return '\n'.join(','.join(x) for x in r).strip()
