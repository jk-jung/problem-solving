def greet_developers(a): 
    for x in a:
        x['greeting'] = f"Hi {x['firstName']}, what do you like the most about {x['language']}?"
    return a
