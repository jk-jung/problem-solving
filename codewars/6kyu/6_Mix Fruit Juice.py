def mix_fruit(v):
    t = {
        'banana': 5,
        'orange': 5,
        'apple': 5,
        'lemon': 5,
        'grapes': 5,
        'avocado': 7,
        'strawberry': 7,
        'mango': 7
    }
    return round(sum(t.get(x.lower(), 9) for x in v) / len(v))
