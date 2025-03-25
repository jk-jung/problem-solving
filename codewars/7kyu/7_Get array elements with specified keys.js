Array.prototype.only = function(keys) {
    return this.filter((x, i) => keys.includes(i))
}
