function sumLength (a){
    let r1 = 0, r2 =0, c =0;
    for(let x of a) {
        if(x === 0){
            if(++c % 2)r2++;
        }else if(x < 0)r2++;
        else r1 += x
    }
    return `${r1} ${r2}`
}