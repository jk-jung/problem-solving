def is_age_diverse(v):
    return len({min(x['age'], 100) // 10 for x in v if x['age'] > 9}) == 10