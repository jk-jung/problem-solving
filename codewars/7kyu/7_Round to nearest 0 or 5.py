def round_to_five(v):
    return [round(x / 5 + 1e-9) * 5 for x in v]
