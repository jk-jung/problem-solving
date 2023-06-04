import requests
from collections import namedtuple
from bs4 import BeautifulSoup

URL = "https://www.codewars.com/users/leaderboard"
def solution():
    User = namedtuple('User', ['name', 'clan', 'honor'])
    result = {}
    html = requests.get(URL).text
    soup = BeautifulSoup(html, 'html.parser')
    for i, x in enumerate(soup.select('tr')[1:]):
        t = str(x).replace('&amp;', '&').split('</td>')
        result[i + 1] = User(t[1].split('/>')[-1].split("</a>")[0], t[-3].split('>')[-1], int(t[-2].split('>')[-1].replace(',', '')))
    R = namedtuple('R', ['position'])
    return R(result)
