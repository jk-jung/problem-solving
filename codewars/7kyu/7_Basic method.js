Array.prototype.max = function () {
    let r = null;
    console.log(this)
    for(let y of this) {
        x = parseInt(y)
        if(x.toString() !== y.toString())return NaN
        if(r === null || r < x)r = x;
    }
    return r;
}