function countZeros(n) {
    let r = 0
    for(let i=1;i<=n;i++)i.toString().split("").forEach(x => r += x == '0');
    return r;
}