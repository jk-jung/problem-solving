function largestPower(n){
    let i;
    for(i=-1;3 ** (i + 1) < n;i++);
    return i;
}