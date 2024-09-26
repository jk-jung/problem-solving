export function clean(array: any[]): any[] {
    return array.filter((x, i) => array.hasOwnProperty(i))
}