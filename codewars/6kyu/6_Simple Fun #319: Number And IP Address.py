import ipaddress
def number_and_IP_address(s):
    if '.' in s: return str(int(ipaddress.IPv4Address(s)))
    return  str(ipaddress.IPv4Address(int(s)))
