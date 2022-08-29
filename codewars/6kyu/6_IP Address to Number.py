import ipaddress

def ip_to_num(ip):
    return int(ipaddress.IPv4Address(ip))

def num_to_ip(num):
    return str(ipaddress.IPv4Address(num))