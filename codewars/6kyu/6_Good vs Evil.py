def good_vs_evil(good, evil):
    a = [1, 2, 3, 3, 4, 10]
    b = [1, 2, 2, 2, 3, 5, 10]

    a = sum(x * int(y) for x, y in zip(a, good.split(' ')))
    b = sum(x * int(y) for x, y in zip(b, evil.split(' ')))

    if a == b: return 'Battle Result: No victor on this battle field'
    if a > b: return 'Battle Result: Good triumphs over Evil'
    return 'Battle Result: Evil eradicates all trace of Good'
