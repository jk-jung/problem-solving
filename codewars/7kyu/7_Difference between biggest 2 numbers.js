function diffBig2(arr) {
    let a = null
    let b = null
    for(let c of arr){
        if(a === null || a < c) {
            b = a
            a = c
        }else if(b === null || b < c){
            b = c
        }
    }
    return a - b
}