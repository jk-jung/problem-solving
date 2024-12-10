function ss(k, s) {
    if(k === 0)return ''
    if(k == 1) return s ? '+' + s : '+1'
    if(k == -1) return s ? '-' + s : '-1'
    if(k > 0) return `+${k}${s}`
    return `${k}${s}`
}

function quadraticFormula(y1,y2,y3) {
    for(let i=-500;i<=500;i++){
        for(let j=-500;j<=500;j++){
            const f = (x) => x * x + i * x + j;
            if(f(1) == y1 && f(2) == y2 && f(3) == y3) {
                let t = 'x^2' + ss(i, 'x') + ss(j, '')
                return [t, f(4), f(5)]
            }
        }
    }
    // Find the formula!
}