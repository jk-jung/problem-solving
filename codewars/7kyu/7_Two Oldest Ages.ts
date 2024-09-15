// return the two oldest/oldest ages within the array of ages passed in.
// it should return the two ages as a sorted array, youngest age first
export function twoOldestAges(ages: number[]): number[] {
    return ages.sort((a, b) => b - a).slice(0, 2).reverse()
}