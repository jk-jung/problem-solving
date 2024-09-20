export function vowelIndices(word: string): number[] {
    let r:number[] = []
    word.toLowerCase().split("").forEach((x: string, i: number) => {
        if('aeiouy'.includes(x))r.push(i + 1);
    })
    return r;
}