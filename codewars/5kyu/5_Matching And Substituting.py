import re


def change(s, prog, version):
    _, _, _, phone, _, ver, _ = s.split('\n')
    phone = phone.split(': ')[-1]
    ver = ver.split(': ')[-1]

    a = re.match("^\+1-\d{3}-\d{3}-\d{4}$", phone)
    b = re.match("^\d+\.\d+$", ver)
    if not a or not b: return "ERROR: VERSION or PHONE"

    r = {
        'Program': prog,
        'Author': 'g964',
        'Phone': '+1-503-555-0090',
        'Date': '2019-01-01',
        'Version': ver if ver == '2.0' else version,
    }

    return ' '.join(f'{k}: {v}' for k, v in r.items())