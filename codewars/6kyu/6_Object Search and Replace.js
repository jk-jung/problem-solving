function solution (data, rep) {
    s = JSON.stringify(data)
    x = 0

    while(s.indexOf('"dynamic"', x) != -1){
        x = s.indexOf('"dynamic"', x)

        if (s[x + 9] != ':')s = s.replace('"dynamic"', `"${rep}"`)

        x ++
    }

    for(x in data) {
        delete data[x]
    }

    r = JSON.parse(s)
    for (x in r)data[x] = r[x]

    return data
}