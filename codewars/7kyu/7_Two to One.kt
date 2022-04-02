package twotoone

fun longest(s1:String, s2:String):String {
    return (s1 + s2).toSet().sorted().joinToString("")
}