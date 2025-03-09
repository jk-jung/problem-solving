function sortTransform(a){
    f = String.fromCharCode
    x = a.length - 2
    y = a.length - 1
    z = () => f(a[0]) + f(a[1]) + f(a[x]) + f(a[y])
    r = [z(),"","",""]
    a.sort((p, q) => p - q)
    r[1] = r[3] = z()
    a.sort((p, q) => q - p)
    r[2] = z()
    return r.join('-')
}