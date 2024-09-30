function minimalSubtractor(n){
    for(let i=0;i<n;i++){
        let t = n;
        let ok = true;
        while(t > 1) {
            t -= i;
            if(t % 2){
                ok = false;
                break;
            }
            t = t / 2;
        }
        if(t == 1 && ok) return i
    }
}