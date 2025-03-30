function danspower(num, power) {
    let r = 1
    for(let i=0;i<power;i++)r *= num
    if(r % 2) return Math.round(r / 10) * 10
    return r
}