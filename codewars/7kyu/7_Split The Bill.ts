export function splitTheBill(x: {[k: string]: number}): {[k: string]: number} {
    let s = Object.values(x).reduce((a, b) => a + b, 0) / Object.values(x).length;
    return Object.fromEntries(Object.entries(x).map(a => ([a[0], Math.round((a[1] - s) * 100)/ 100 ])))
}