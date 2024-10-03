function rnd() {
    return Math.floor(Math.random() * 10)
}

const t = [ ['A', 'A', 'B', 'C', 'B', 'D', 'A', 'C', 'C', 'D'], ['A', 'B', 'B', 'C', 'B', 'D', 'A', 'A', 'C', 'D'], ['A', 'A', 'A', 'C', 'B', 'D', 'A', 'C', 'C', 'D'], ['C', 'A', 'B', 'C', 'B', 'C', 'D', 'B', 'C', 'A'], ['A', 'A', 'B', 'D', 'B', 'B', 'A', 'C', 'B', 'A'], ['B', 'A', 'B', 'C', 'B', 'D', 'A', 'B', 'C', 'B'], ['A', 'A', 'D', 'C', 'A', 'D', 'B', 'C', 'C', 'C'], ['B', 'A', 'B', 'C', 'B', 'D', 'B', 'C', 'C', 'D'], ['D', 'A', 'B', 'C', 'B', 'D', 'A', 'C', 'C', 'D'], ['A', 'A', 'B', 'C', 'B', 'D', 'A', 'C', 'C', 'D'], ]

function array10(){
    let r = []
    for(let i=0;i<10;i++){
        r.push(t[rnd()])
    }
    return  r

}