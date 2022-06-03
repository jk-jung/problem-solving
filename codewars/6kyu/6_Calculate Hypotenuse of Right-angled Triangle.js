function calculateHypotenuse(a,b){
    try {
        if( a <= 0 || b <= 0 || typeof(a) != typeof(1) || typeof(b) != typeof(1) || isNaN(a) || isNaN(b))
            throw 'error'
        return Math.round(Math.sqrt(a * a + b * b) * 1000) / 1000
    }catch (e){
        throw 'error'
    }
}