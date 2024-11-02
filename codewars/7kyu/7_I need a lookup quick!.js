Array.prototype.toDictionary = function (keyFn, valueFn) {
    let r = {}
    this.forEach(x => r[keyFn(x)] = valueFn ? valueFn(x) : x)
    return r
}