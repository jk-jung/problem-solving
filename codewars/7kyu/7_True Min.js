function min(a, b){
    if(a===undefined || b===undefined) return NaN;
    if(isNaN(a) || isNaN(b)) return NaN;
    if(a===null) a = 0;
    if(b===null) b = 0;
    return (a<b)?a:b;
}