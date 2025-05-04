def get_total(costs, items, tax):
    return round(sum(costs.get(x, 0) * (1 + tax) for x in items), 2)
