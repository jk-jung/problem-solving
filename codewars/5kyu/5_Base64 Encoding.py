import base64


def to_base_64(s):
    return base64.b64encode(s.encode('ascii')).decode('ascii').replace('=', '')


def from_base_64(s):
    return base64.b64decode(s.encode('ascii') + b'=' * (-len(s) % 4)).decode('ascii')
