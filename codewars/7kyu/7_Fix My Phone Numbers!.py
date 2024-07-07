def is_it_a_num(s: str) -> str:
    s = ''.join([x for x in s[s.find('0'):] if x.isdigit()])
    return s[:11] if len(s) == 11 else 'Not a phone number'
