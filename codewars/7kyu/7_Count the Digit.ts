export class G964 {
    public static nbDig(n: number, d: number): number {
        let r = 0
        let c = d.toString();
        for(let i=0;i<=n;i++){
            let s = (i * i).toString();
            r += s.split("").filter((x: string) => x == c).length;
        }
        return r;
    }
}