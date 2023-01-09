def proofread(s):
    s = s.lower().replace('ie', 'ei')
    return '. '.join([x.capitalize() for x in s.split('. ')])