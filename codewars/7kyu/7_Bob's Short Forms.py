def short_form(s):
    return ''.join([x if i == 0 or i + 1 == len(s) or x.lower() not in 'aeiou' else '' for i, x in enumerate(s)])
