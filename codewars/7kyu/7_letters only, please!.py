import re


def remove_chars(s):
    return re.sub('[^a-zA-Z ]', '', s)
