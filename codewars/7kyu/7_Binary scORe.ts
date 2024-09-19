export function score(n: number): number {
    let r = 1;
    while(r <= n)r *= 2;
    return r - 1;
}