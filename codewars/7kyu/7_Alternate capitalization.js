function capitalize(s){
    return [s.split("").map((x,i)=>i%2?x.toLowerCase():x.toUpperCase()).join(""),s.split("").map((x,i)=>i%2?x.toUpperCase():x.toLowerCase()).join("")];
};
