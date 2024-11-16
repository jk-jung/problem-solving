// extend all numbers with toBits()
Number.prototype.toBits = function(length = 8) {
    let r = '', t = this
    for(let i=0;i<length || t;i++) {
        r = (t & 1) + r
        t >>= 1
    }
    return r
}