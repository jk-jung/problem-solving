import re
def valid_phone_number(n):
    return bool(re.compile(r'^\(\d{3}\) \d{3}-\d{4}$').match(n))
