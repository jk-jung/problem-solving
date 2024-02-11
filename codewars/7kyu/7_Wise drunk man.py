import re
def wdm(talk):
    return re.sub('[ ]+', ' ', talk.replace('puke', '').replace('hiccup', '')).strip()
