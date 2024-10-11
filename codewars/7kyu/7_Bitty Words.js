function bittyWords(words, bits) {
    a = words.split(" ");
    a.reverse()
    r = []
    for (let i = 0; i < a.length; i++) {
        if (bits >> i & 1) r.push(a[i])
    }
    r.reverse()
    return r.join(" ")
}