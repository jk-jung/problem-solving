def status(v):
    return [x[1] for x in sorted(enumerate(v),key=lambda x: x[0] + len([y for y in v if y < x[1]]))]