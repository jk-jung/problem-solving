function subPowerOf2(s, p) {
    let t = 0
    let rst = []
    let k = (1 << p) - 1
    let kk = 1 << p
    r = []
    for(let i=s.length-1;i>=0;i--){
        let x = parseInt(s[i]);
        r.push(0)
        for(let j=r.length-1, base=1;j>=0;j--, base = base * 10 % kk){
            r[j] = (r[j] + base * x) % kk;
        }
        if(r.length > 30) {
            let y = r.shift()
            if((y & k) == 0)t ++;
        }
        let cnt = t;
        for(let y of r)if((y & k) == 0) cnt ++;
        rst.push(cnt)
    }

    return rst.reverse()
}