export function singleDigit(n: number): number {
    if(n.toString().length == 1) return n;
    let r = 0;
    for(let i=0;i<32;i++)r += (n >> i & 1);
    return singleDigit(r);
}