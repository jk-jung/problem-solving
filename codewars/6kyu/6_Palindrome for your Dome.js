function palindrome(s) {
    let r = ''
    s = s.toLowerCase()
    for (let x of s)
        if ('a' <= x && x <= 'z') r += x

    for (let i = 0; i < r.length; i++) {
        if (r[i] != r[r.length - i - 1]) return false
    }
    return true
}