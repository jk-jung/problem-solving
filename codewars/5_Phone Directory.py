import re
from collections import defaultdict

reg_phone = re.compile('\+[0-9]{1,2}-[0-9]{3}-[0-9]{3}-[0-9]{4}')
reg_name = re.compile('<.*>')
reg_address = re.compile('[^A-Za-z 0-9\-\.]')


def extract(x, reg):
    return reg.sub('', x), reg.search(x)[0]


def phone(strng, num):
    r = defaultdict(list)

    for x in strng.strip().split('\n'):
        x, phone = extract(x, reg_phone)
        x, name = extract(x, reg_name)

        phone = phone[1:]
        name = name[1:-1]
        address = reg_address.sub(' ', x).strip()
        address = ' '.join(address.split())
        r[phone].append(f"Phone => {phone}, Name => {name}, Address => {address}")

    t = r[num]
    if len(t) == 0: return f"Error => Not found: {num}"
    if len(t) > 1: return f"Error => Too many people: {num}"
    return t[0]
