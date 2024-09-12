export function powerOf4(n: any): boolean {
    if(typeof n !== typeof 1)return false
    if(n == 0)return false
    while(n !== 1 && n % 4 == 0)n = n / 4
    return n == 1
}