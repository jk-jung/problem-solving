Function.prototype.wrap = function(f) {
    return (...args) => f(this, ...args)
}