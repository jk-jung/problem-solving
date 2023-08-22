def find_similar_dogs(t):
    m = max([len(dogs[t] & y) for x, y in dogs.items() if x != t])
    return set(x for x, y in dogs.items() if x != t and len(dogs[t] & y) == m)
