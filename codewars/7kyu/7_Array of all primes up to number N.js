var primeArray = function(n) {
    var r = [];
    for(let i=2;i<=n;i++){
        let ok = true;
        for(let x of r)if(i % x == 0)ok = false
        if(ok)r.push(i)
    }
    return r;
}