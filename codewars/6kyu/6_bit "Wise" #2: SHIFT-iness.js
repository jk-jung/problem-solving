Number.prototype.twos = function(n) {
    r = ''
    for(let i = n - 1;i>=0;i--) r += (this >> i & 1).toString()
    return r
}