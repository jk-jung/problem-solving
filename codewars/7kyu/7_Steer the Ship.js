var steer = function(x, y) {
    a = 1
    b = Math.sqrt(x * x + y * y)
    c = Math.sqrt(x * x + (y - 1) * (y - 1))
    cc = (a * a + b * b - c * c) / 2 / a / b
    v = Math.round(Math.acos(cc) * 180 / Math.PI * 100)/100

    if (x < 0)return `L: ${v}`
    return `R: ${v}`
}