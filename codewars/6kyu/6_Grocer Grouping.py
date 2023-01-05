def group_groceries(g):
    r = []
    for k in ['fruit', 'meat', 'other', 'vegetable']:
        def f(x):
            if k == 'other':
                return not x.startswith('fruit') and not x.startswith('meat') and not x.startswith('vegetable')
            return x.startswith(k)
        r.append(k + ':' + ','.join(sorted([x.split('_')[1] for x in g.split(',') if f(x)])))
    return '\n'.join(r)
