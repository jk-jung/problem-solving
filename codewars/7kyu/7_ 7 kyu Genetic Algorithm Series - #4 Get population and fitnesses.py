def map_population_fit(a, b):
    return [ChromosomeWrap(x, b(x)) for x in a]
