function mathEngine(arr) {
    if(!arr)return 0
    let a =1,b=0
    for(let x of arr){
        if(x >= 0)a *= x
        else b += x
    }
    return a + b
}