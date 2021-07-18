/**
 * CSV Parser.  Takes a string as input and returns
 * an array of arrays (for each row).
 *
 * @param input String, CSV input
 * @param separator String, single character used to separate fields.
 *        Defaults to ","
 * @param quote String, single character used to quote non-simple fields.
 *        Defaults to "\"".
 */
function parseCSV(input, separator, quote) {
    separator = separator || ',';
    quote = quote || '"';

    // Create your implementation here

    let r = [['']]
    let state = ''

    let add = (x) => r[r.length - 1][r[r.length - 1].length - 1] += x
    let cur = () => r[r.length - 1][r[r.length - 1].length - 1]

    for (let x of input) {
        let c = r[r.length - 1][r[r.length - 1].length - 1]
        console.log(x)
        if (state === 'q') {
            if (x === quote) {
                if (cur().length === 0) state = ''
                else state = 'q1'
            }
            else add(x)
        } else if (state === 'q1') {
            if (x === quote) {
                add(quote)
                state = 'q'
            } else {
                if (x === separator) r[r.length - 1].push('')
                else if (x === '\n') r.push([''])
                state = ''
            }
        } else {
            if (x === separator) r[r.length - 1].push('')
            else if (x === '\n') r.push([''])
            else if (x === quote && cur().length === 0) state = 'q'
            else add(x)
        }
    }

    return r

}