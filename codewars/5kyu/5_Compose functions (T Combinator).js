var compose = function(x, ...funcs) {
    for(let f of funcs) x = f(x)
    return x
}