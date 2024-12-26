function paintTiles(costs) {
    let r = [0,0,0,0];
    for(let c of costs) {
        let t = [];
        for(let i=0;i<4;i++){
            let v = 1 << 30;
            for(let j=0;j<4;j++){
                if(i != j && r[j] < v)v = r[j]
            }
            t[i] = v + c[i]
        }
        r = t
    }
    return Math.min(...r)
}