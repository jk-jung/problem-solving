def find_admin(a, b): 
    return [x for x in a if x['language'] == b and x['githubAdmin'] == 'yes']
