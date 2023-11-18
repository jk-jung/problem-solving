def part(w):
    for x in {*adjectives, *nouns}:
        for y in nouns:
            if x + y == w: return 'compound'
    if w in adjectives: return 'adjective'
    if w in nouns: return 'common'
    return 'neither'
