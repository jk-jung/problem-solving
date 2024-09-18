export function number(array: string[]): string[]{
    return array.map((x, i) => `${i + 1}: ${x}`)
}