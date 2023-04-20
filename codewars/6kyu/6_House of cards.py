def house_of_cards(n):
    assert n >= 1, ''
    return (n + 1) * (n + 2) + (n ) * (n + 1) // 2
