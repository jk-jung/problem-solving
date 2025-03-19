function runYourString (arg, obj) {
    eval(`function f(){\n${obj.param}=arg;\n${obj.func}\n}`)
    return f()
}
