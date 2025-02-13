var mispelled = function(a, b, sub=true)
{
    let r = 0
    for(let i=0;i<Math.max(a.length, b.length);i++)
        if(a[i] != b[i])r ++
    return r <= 1 || (sub && (mispelled(a, b.substr(1), false) || mispelled(a.substr(1), b, false)))
}
