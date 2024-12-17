Array.prototype.remove_ = function(a, b){
    return a.filter(x => !b.includes(x))
}