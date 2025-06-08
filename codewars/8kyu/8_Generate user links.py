import urllib.parse
def generate_link(x):
    return 'http://www.codewars.com/users/' + urllib.parse.quote(x)