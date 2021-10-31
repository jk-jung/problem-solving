function add (x, y) {
    while(y!=0) {
        let t=x&y;
        x=x^y;
        y=t<<1;
    }
    return x;
}
