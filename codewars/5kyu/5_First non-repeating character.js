function firstNonRepeatingLetter(s) {
    for (let i = 0; i < s.length; i++) {
        let ok = 1
        for (let j = 0; j < s.length; j++) if (i !== j) {
            if (s[i].toUpperCase() === s[j].toUpperCase()) ok = 0
        }
        if (ok) return s[i]
    }
    return ''
}