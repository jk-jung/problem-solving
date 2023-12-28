export function sumArray(array:number[] | null) : number {
    if (array == null) return 0
    let r = array.sort((a, b) => a - b).slice(1, array.length  - 1)
    return r.reduce((x, y) => x + y, 0)
}