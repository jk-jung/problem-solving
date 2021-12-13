import requests
def get_member_since(username):
    url = f'https://www.codewars.com/users/{username}'
    s = requests.get(url).content.decode('utf-8')
    i = s.find('Member Since')
    return s[i+17:i+25]