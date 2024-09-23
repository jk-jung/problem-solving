export function addLetters(...letters: string[]) {
    if(letters.length == 0)return 'z'
    let s = -1, t = 'a'.charCodeAt(0);
    for(let x of letters) s += x.charCodeAt(0) - t + 1;
    return String.fromCharCode(t + s % 26)
}
