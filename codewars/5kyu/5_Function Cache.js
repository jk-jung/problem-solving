function cache(func) {
    let t = {}
    return function x() {
        let a = arguments
        let k = JSON.stringify(a)
        if (!(k in t)) t[k] = func(...a)
        return t[k]
    }
}