def pizza_rewards(c, min_orders, min_price):
    return [x for x in c if len([y for y in c[x] if y >= min_price]) >= min_orders]
