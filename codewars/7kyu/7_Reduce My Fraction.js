function gcd(a, b) {
    return b ? gcd(b, a % b) : a;
}
function reduce([a, b]) {
    const g = gcd(a, b)
    return [a / g, b / g]
}