function peelPairs(str, n) {
    let done = true
    let r = "", removed = {}
    for(let i=0;i<str.length;i++){
        if(removed[i])continue;
        for(let j=i+1;j<str.length;j++){
            if(removed[j])continue;
            if(parseInt(str[i]) + parseInt(str[j]) === n) {
                removed[i] = 1;
                removed[j] = 1;
                done = false;
                break;
            }
        }
        if(removed[i])continue;
        r += str[i]
    }
    if(!done)return peelPairs(r, n)
    return r
}