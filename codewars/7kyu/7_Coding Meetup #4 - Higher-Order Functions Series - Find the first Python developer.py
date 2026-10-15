def get_first_python(y):
    return next((f"{x['first_name']}, {x['country']}" for x in y if x['language'] == 'Python'), "There will be no Python developers")
