//Returns a valid Binary Search Tree, built from the array passed as parameter.
function toBSTArray(array) {
    let bst = [];

    for (let x of array) {
        let k = 0
        while(bst[k]) {
            if (x <= bst[k]) k = k * 2 + 1
            else k = k * 2 + 2
        }
        bst[k] = x
    }
    return bst;
}

//Returns true is the array parameter is a valid BST, false otherwise.
function isBSTArray(v) {
    if (arguments.length === 0) return true;
    for (let i = 0;i<v.length;i++){
        let a = v[i*2 + 1]
        let b = v[i*2 + 2]
        if(a !== undefined && v[i] < a) return false
        if(b !== undefined && v[i] > b) return false
    }
    return true;
}

function dfs(i, v, r) {
    let a = i*2 + 1
    let b = i*2 + 2

    if(v[a] !== undefined) dfs(a, v, r)
    if(v[i] !== undefined) r.push(v[i])
    if(v[b] !== undefined) dfs(b, v, r)
}

function toArray(v) {
    if (!isBSTArray(v)) throw new Error('The parameter must be a BSTArray');

    let r = [];
    dfs(0, v, r)
    return r;
}