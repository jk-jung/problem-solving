function sumEvenNumbers(v) {
    return v.reduce((y, x) => y + (x % 2 ? 0 : x), 0)
}