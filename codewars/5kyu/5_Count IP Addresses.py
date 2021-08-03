import ipaddress

def ips_between(s, e):
    s = int(ipaddress.IPv4Address(s))
    e = int(ipaddress.IPv4Address(e))
    return e - s

