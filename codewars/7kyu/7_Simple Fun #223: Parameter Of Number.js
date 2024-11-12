function parameter(n) {
    let a = 0, b = 1;
    n.toString().split("").forEach(x => {
        a += parseInt(x)
        b *= parseInt(x)
    })
    let g = 1
    for(let i=1;i<=a;i++){
        if(a % i == 0 && b % i == 0)g = i;
    }

    return a * b / g
}