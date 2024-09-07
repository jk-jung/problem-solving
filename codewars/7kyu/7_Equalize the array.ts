export function equalize(array:number[]):string[] {
    if (array.length === 0)return []
    const base = array[0]
    return array.map(x => {
        if(x >= base) return `+${x - base}`
        return `${x - base}`
    })
}
