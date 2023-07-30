def get_most_profit_from_stock_quotes(v):
    r = 0
    for i in range(len(v)):
        r += max(0, max(v[j] - v[i] for j in range(i, len(v))))
    return r
