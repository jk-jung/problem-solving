export function authList(arr:string[]):boolean {
    for(let x of arr) {
        console.log(x)
        if(!(6 <= x.length && x.length <= 10))return false;
        let ck1 = false, ck2 = false;
        for(let c of x) {
            if('0' <= c && c <= '9') ck1 = true;
            else if('a' <= c && c <= 'z') ck2 = true;
            else return false
        }
        if(!ck1 || !ck2)return false;
    }
    return true;
}