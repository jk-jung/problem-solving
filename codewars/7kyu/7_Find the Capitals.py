def capital(y):
    return [f"The capital of {x.get('state', x.get('country'))} is {x['capital']}" for x in y]