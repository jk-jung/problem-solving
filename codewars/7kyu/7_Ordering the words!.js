function orderWord(s){
    if(typeof(s) != typeof('') || s === '')return "Invalid String!"
    return s.split("").sort((x, y) => x.charCodeAt(0) - y.charCodeAt(0)).join('')
}