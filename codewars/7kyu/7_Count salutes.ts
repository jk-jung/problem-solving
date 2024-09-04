export function countSalutes(hallway: String): number {
    let r = 0, cnt = 0
    hallway.split("").forEach((x: String) => {
        if(x == '>')cnt ++;
        if(x == '<') r += cnt;
    })

    return r * 2;
}