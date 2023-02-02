import requests
import re

def get_leaderboard_honor():
    t = requests.get('https://www.codewars.com/users/leaderboard')
    return [int(x.replace(',', '')) for x in re.findall('<td class="honor">([0-9,]*)</td>', str(t.content))]
