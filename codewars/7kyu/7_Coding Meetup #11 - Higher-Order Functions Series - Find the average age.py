def get_average(a): 
    a = [x['age'] for x in a]
    return round(sum(a) / len(a))
