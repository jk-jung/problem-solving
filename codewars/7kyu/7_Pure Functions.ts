type State = {modifier: number}

const state:State = {modifier: 2}

export function solution(arr: number[], options:State) {
    const r: number[] = []
    for (let i = 0; i < arr.length; ++i) {
        r.push(arr[i] + 2 * options.modifier);
    }
    return r
}
