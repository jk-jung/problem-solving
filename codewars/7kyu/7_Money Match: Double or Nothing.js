function doubleOrNothing(a, b, c) {
    let v = b;
    for(let i=0;i<c;i++){
      if(v > a) return "I'll pay you back later";
      v *= 2;
    }
    v = v / 2;
    return a - v;
}