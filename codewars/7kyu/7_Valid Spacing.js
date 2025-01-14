function validSpacing(s) {
    if(s.indexOf("  ") !== -1)return false
    return s == s.trim()
}