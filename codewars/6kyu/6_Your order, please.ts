export function order(words:string):string{
    return words.split(' ').sort((a, b) => {
        let a1 = a.split('').find(x => '1' <= x && x <= '9') || '1'
        let b1 = b.split('').find(x => '1' <= x && x <= '9') || '1'

        return a1 < b1 ? -1 : 1
    }).join(' ')
}