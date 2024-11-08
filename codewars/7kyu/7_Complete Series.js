function completeSeries(a) {
    let s = new Set(a);
    if (s.size === a.length) {
        let r = [];
        for(let i=0;i<=Math.max(...a);i++)r.push(i);
        return r;
    }else {
        return [0]
    }
}