// the input and output values are in BigInt type
// https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/BigInt
export function queens(n: bigint): bigint {
    if (n <= 0) return n * BigInt(0);
    return n * n - n * BigInt(3) + BigInt(2);
}