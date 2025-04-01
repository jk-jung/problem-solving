function isMagicThree(a) {
    for (let x of a)
        for (let y of a)
            for (let z of a)
                if (x + y + z === 0) return true;
    return false;
}