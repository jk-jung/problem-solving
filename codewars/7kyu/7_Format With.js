String.prototype.formatWith = function () {
    let s = String(this)
    for(let i=0;i<arguments.length;i++)
        s = s.replaceAll(`\{${i}\}`, arguments[i])
    return s
}