def strip_url_params(url, params_to_strip=None):
    params_to_strip = params_to_strip or []
    if '?' not in url:
        return url
    u, params = url.split('?')
    r = {}
    for x in params.split('&'):
        k, v = x.split('=')
        if k not in r and k not in params_to_strip:
            r[k] = v
    if not r:
        return u
    return u + '?' + '&'.join(f'{k}={v}' for k, v in r.items())