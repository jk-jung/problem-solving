function findOddDigits(n, k) {
    let r = 0;
    n = n.toString();
    for(let x of n){
        if(parseInt(x) % 2 && k > 0){
            k --;
            r = r * 10 + parseInt(x)
        }
    }
    if(k)return 0
    return r
}