def is_ruby_coming(a): 
    return any(x['language'] == 'Ruby' for x in a)
