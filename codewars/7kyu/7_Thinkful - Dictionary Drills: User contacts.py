def user_contacts(data):
    return {x[0]: None if len(x) == 1 else x[1] for x in data}