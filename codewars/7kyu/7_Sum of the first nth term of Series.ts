export function SeriesSum(n:number):string
{
    let s = 1,r = 0;
    for(let i=0;i<n;i++){
        r += 1 / s;
        s += 3
    }
    return r.toFixed(2)
}