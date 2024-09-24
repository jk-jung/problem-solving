export function openOrSenior(data:number[][]):string[]{
    return data.map((x: any) => x[0] >= 55 && x[1] > 7 ? "Senior" : "Open")
}