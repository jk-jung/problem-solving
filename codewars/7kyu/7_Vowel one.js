function vowelOne(s){
    return s.toLowerCase().split("").map(x => 'aeiou'.includes(x) ? '1': '0').join("")
}