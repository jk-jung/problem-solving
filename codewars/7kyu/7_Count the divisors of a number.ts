export function divisors(n: number) {
    let r = 0;
    for(let i=1;i*i<=n;i++){
        if(n % i == 0){
            r += 2;
            if(i * i == n)r --;
        }
    }
    return r
}