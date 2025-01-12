function primes(start, end){
    let r = []
    for(let i=start;i<=end;i++){
        let ok = i !== 1
        for(let j=2;j<i;j++)if(i % j == 0)ok = false
        if(ok)r.push(i)
    }
    if(r.length == 0)return null
    return r
}
