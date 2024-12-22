function maximizeEarnings(v,k) {
    let n = v.length
    let d = [[0]];
    for(let i=0;i<n;i++){
        let r = 0
        for(let j=0;j<=k;j++)r = Math.max(r, d[i][j] || 0)
        d.push([r]);
        for(let j=1;j<=k;j++){
            d[i + 1][j] = (d[i][j-1] || 0) + v[i]
        }
    }
    let r = 0
    for(let j=0;j<=k;j++)r = Math.max(r, d[n][j] || 0)
    return r;
}