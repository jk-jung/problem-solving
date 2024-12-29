function arraySum(arr) {
    let r = 0
    for(let x of arr){
        if(typeof(x) === typeof([]))r += arraySum(x)
        else if(typeof(x) === typeof(1)) r += x
    }
    return r
}