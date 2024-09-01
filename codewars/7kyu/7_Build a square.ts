export function generateShape(n: number): string {
    let r: string = ''
    for(let i=0;i<n;i++){
        for(let j=0;j<n;j++)r += '+'
        r += '\n'
    }
    return r.trim()
}