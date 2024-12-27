function sevenAte9(str) {
    while(true) {
        r = str.replaceAll("797", "77")
        if(r == str)return r
        str = r
    }
}