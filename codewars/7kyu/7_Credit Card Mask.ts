// return masked string
export function maskify(cc: string): string {
    return '#'.repeat(Math.max(0, cc.length - 4)) + cc.slice(-4)
}