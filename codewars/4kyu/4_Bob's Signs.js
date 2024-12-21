var SignMaster = function() {
    this.add = 0
    this.rem = 0
};

SignMaster.prototype.changePrices = function(prices) {
    if('add' in prices)this.add = prices.add
    if('rem' in prices)this.rem = prices.rem

    console.log(this.add, this.rem)
};

SignMaster.prototype.estimatePrice = function(a, b) {
    let n = a.length
    let m = b.length
    let d = [[]]
    for(let i=0;i<=m;i++)d[0].push(i * this.add)
    for(let i=1;i<=n;i++){
        d.push([i * this.rem])
        for(let j=1;j<=m;j++){
            d[i][j] = Math.min(
                (d[i-1][j] || 0) + this.rem,
                (d[i][j-1] || 0) + this.add,
                (d[i-1][j-1] || 0) + (a[i-1] === b[j-1] ? 0 : this.rem + this.add)
            )
        }
    }
    return d[n][m];
};