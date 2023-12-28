def four_seasons(d):
    if d > 365: return 'The year flew by!'
    if d < 80: return 'Winter Season'
    if d < 172: return 'Spring Season'
    if d < 264: return 'Summer Season'
    if d < 355: return 'Autumn Season'
    return 'Winter Season'
