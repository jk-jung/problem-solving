export function isVeryEvenNumber(n: number): boolean {
    if (n < 10) return n % 2 == 0;
    let r = 0;
    n.toString().split("").forEach(x => {r += parseInt(x)})
    return isVeryEvenNumber(r);
}