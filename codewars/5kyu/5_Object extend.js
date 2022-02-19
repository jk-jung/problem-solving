var extend = function () {
    let r = arguments[0]
    if (arguments.length === 0 || !isObject(r)) return {}
    for (let x of arguments) {
        if (isObject(x)) {
            Object.entries(x).forEach((y) => {
                if (y[0] in r) ;
                else r[y[0]] = y[1]
            })
        }
    }
    return r
}