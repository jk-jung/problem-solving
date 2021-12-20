function isPrime(n) {
    if(n <= 1)return false
    let x = 2
    while (x * x <= n) {
        while(n % x == 0) return false
        x ++
    }
    return true
}

function getPrimes(s, e) {
    if(s > e) {
        let t = e
        e = s
        s = t
    }
    let r = []
    for (let i = s; i<=e;i++)if(isPrime(i))r.push(i)
    return r
}