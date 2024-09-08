export function solve(s: string) {
    let r = 0, c = 0;
    for(let i=0;i<s.length;i++){
        if('aeiou'.indexOf(s[i]) !== -1)c ++;
        else c = 0;
        r = Math.max(r, c)
    }
    return r;
}