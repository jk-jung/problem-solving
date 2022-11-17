def will_fit(a, b):
    return all(x + 2 <= y  for x, y in zip(sorted(a), sorted(b)))
