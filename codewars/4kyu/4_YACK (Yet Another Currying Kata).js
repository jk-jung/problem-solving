function yack(fn, ...args) {
    function func(...x) {
        if (x.length >= fn.length) return fn(...x)
        return (...y) => func(...x, ...y)
    }
    return func(...args)
}