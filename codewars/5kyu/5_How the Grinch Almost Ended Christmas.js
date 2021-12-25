function prioritizeMissiles(v){
    v.sort((x, y) => x.distance / x.speed - y.distance / y.speed)
    return v.map(x=>x.name)
}