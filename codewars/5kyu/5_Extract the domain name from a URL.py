def domain_name(url):
    return url.replace('http://', '').replace('https://', '').replace('www.', '').split('.')[0]
