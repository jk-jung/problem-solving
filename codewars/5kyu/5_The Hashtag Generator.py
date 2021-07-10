def generate_hashtag(s):
    r = ''.join(x[0].upper() + x[1:].lower() for x in s.split() if x)
    return '#' + r if r and len(r) < 139 else False