export function inviteMoreWomen (L: number[]): boolean {
    let m = 0;
    L.forEach(x => {
        if(x === 1)m ++;
    })
    return m > L.length - m
}