def reload_sheeps(a):
    return ['sheep' for x in a if ''.join(sorted(x)) == 'eehps']
