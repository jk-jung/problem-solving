function tetration(x,y){
    if(y == 0)return 1;
    let r = x;
    while(--y){
        r = Math.pow(x, r)
    }
    return r;
}