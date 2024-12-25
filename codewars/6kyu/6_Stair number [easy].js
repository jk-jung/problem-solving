const solution = (n) => {
    let a = [0, 1, 1, 1, 1, 1, 1, 1, 1, 1]

    for(let i=1;i<n;i++){
        let b = [0,0,0,0,0,0,0,0,0,0]
        for(let j=0;j<=9;j++){
            if(j - 1 >= 0)b[j-1] = (b[j-1] + a[j]) % 1000000007;
            if(j + 1 <= 9)b[j+1] = (b[j+1] + a[j]) % 1000000007;
        }
        a = b
    }

    return a.reduce((x, y) => (x + y) % 1000000007, 0)
}