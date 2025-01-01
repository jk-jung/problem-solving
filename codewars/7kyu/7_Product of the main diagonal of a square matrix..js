function mainDiagonalProduct(mat){
    let r=1;
    for(let i=0; i<mat.length; i++)
        r*=mat[i][i];
    return r;
}