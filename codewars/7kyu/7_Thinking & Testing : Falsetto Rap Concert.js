function testit(s) {
    let r = "";
    let op = 1
    for (let x of s) {
        c = x.charCodeAt(0);
        if (!(c > 64 && c < 91) && // upper alpha (A-Z)
            !(c > 96 && c < 123)) { // lower alpha (a-z)
            r += x
        } else {
            c = c + op
            if (c == 91) c = 65
            if (c == 64) c = 90
            if (c == 123) c = 97
            if (c == 96) c = 122
            r += String.fromCharCode(c)
        }
        op = -op
    }
    return r;
}
