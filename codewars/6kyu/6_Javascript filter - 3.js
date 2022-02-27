function searchNames(v) {
    let r = []
    for (let i = 0; i < v.length; i += 2) {
        if (v[i][0] == '.' || v[i][v[i].length - 1] == '.')
            r.push(v[i + 1])
    }
    return r.filter(x => true)
}