export function movie(card: number, ticket: number, perc: number): number {
    let value: number = card;
    let current: number = ticket;
    for(let i=1;;i++){
        current *= perc;
        value += current;
        if(Math.ceil(value) < ticket * i)return i
    }
    return -1
}