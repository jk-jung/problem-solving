def recycle(a):
    return tuple(
        [x['type'] for x in a if x['material'] == t or x.get('secondMaterial') == t]
        for t in ['paper', 'glass', 'organic', 'plastic']
    )