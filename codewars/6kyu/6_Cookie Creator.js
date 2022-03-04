function setCookie(name, value, domain, path, expires){
    if(typeof(name) !== typeof("")) return 'Must include a cookie name'
    if(typeof(value) !== typeof("")) value = name

    let s = `document.cookie = "${name}=${value}`
    if(expires) {
        let exp = ''
        if (typeof(expires) === typeof(1))
            exp = new Date(Date.now() + 86400000 * expires).toString().slice(0, 15) + ' 00:00:00'
        else {
            exp = new Date(expires).toString().slice(0, 15) + ' 00:00:00'
        }

        s += `; expires=${exp}`
    }
    path = path || '/'
    s += `; path=${path}`
    if(domain) s += `; domain=${domain}`
    return s + '"'
}