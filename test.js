function increasingSequence(arr) {
    memo = {};

    function recursiveSolve(arr) {
        const memoKey = arr.toString();
        if (!memo[memoKey]) {
            if (arr.length === 1) {
                memo[memoKey] = arr;
            } else if (
                arr.reduce((acc, curr, idx) => {
                    return acc && (idx === 0 || curr > arr[idx - 1]);
                }, true)
            ) {
                memo[memoKey] = arr;
            } else {
                memo[memoKey] = arr.reduce((acc, _, idx) => {
                    const subIS = recursiveSolve([...arr.slice(0, idx), ...arr.slice(idx + 1)]);
                    if (acc.length <= subIS.length) {
                        return subIS;
                    }
                    return acc;
                }, []);
            }
        }
        return memo[memoKey];
    }

    return recursiveSolve(arr);
}