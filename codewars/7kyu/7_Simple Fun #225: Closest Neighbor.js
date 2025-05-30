function closestNeighbor(n, a, b, c) {
    let g = 0
    for(let i=1;i<=a*b*c;i++){
        if(i % a == 0 && i % b == 0 && i % c == 0){
            g = i;
            break;
        }
    }
    t = (Math.floor(n / g) + 1) * g
    let k = t;
    while(k >= n)k -= g
    return [k, t]

}