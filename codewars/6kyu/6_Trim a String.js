String.prototype.trim = function() {
    let s = this.slice(0)
    console.log(s)
    while(s.length > 0 && ' \t\n\r'.includes(s[0]) )s = s.slice(1)
    while(s.length > 0 && ' \t\n\r'.includes(s[s.length - 1]))s = s.slice(0, s.length - 1)
    console.log(s)
    return s
};