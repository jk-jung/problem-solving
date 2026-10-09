def count_developers(a):
    return len([x for x in a if x['continent'] == 'Europe' and x['language'] == 'JavaScript'])
