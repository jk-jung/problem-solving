export function rowSumOddNumbers(n: number): number {
    function t(n: number) {
        let r = 0, k = 1
        for(let i=0;i<n;i++){
            for(let j=0;j<=i;j++){
                r += k;
                k += 2;
            }
        }
        return r
    }
    return t(n) - t(n-1);
}