def autocomplete(s, d):
    s = ''.join(x for x in s if x.isalpha())
    return [x for x in d if x.lower().startswith(s.lower())][:5]