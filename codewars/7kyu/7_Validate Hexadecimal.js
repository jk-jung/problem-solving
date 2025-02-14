function isHex(str) {
    if(str.length != 3 && str.length != 6)return false
    for(let x of str.split(""))
        if (!"0123456789abcdefABCDEF".includes(x)) return false
    return true
};
