Object.prototype.hash = function(s) {
    let t = this
    try {
        for(let x of s.split('.')) {
            t = t[x]
        }
    } catch {
        return undefined
    }
    return t
}