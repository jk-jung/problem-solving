function orArrays(a, b, c){
    let r = [];
    for(let i=0;i<Math.max(a.length, b.length); i++)
        r.push((a[i] === undefined ? c : a[i]) | (b[i] === undefined ? c : b[i]));
    return r;
}