const maxSpan = (v) => {
    let t = {}, r = 1;
    for(let i=0;i<v.length;i++){
        let x = v[i];
        if(t[x] === undefined)t[x] = i;
        else r = Math.max(r, i - t[x] + 1);
    }
    return r;
}