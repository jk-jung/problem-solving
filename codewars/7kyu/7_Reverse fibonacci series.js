function reverseFibo(n){
    let r = '', a =0, b = 1;
    for(let i=0;i<n;i++){
        r = a + r;
        [a, b] = [b, a + b]
    }
    return r
}
