export const f = (x: number, cc: { a: number, b: number, c: number }): number => {
    if(cc.a === x)return cc.b;
    if(cc.b === x)return cc.c;
    if(cc.c === x)return cc.a;
    return -1
}
