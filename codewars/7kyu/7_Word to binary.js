function wordToBin(str) {
    return str.split("").map(x => x.charCodeAt(0).toString(2).padStart(8, '0'))
}
