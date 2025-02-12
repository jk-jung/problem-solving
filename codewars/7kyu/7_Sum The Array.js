//Your code goes here
Array.prototype.sum = function () {
    let r = 0
    for(let x of this) r += x
    return r
}
