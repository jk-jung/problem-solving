function Machine(wordList) {
    return {
        player: function (word) {
            let used = {}, ok = {}
            let lst = wordList.filter(x => x.length === word)
            let last_result = '_' * word, last_char = ''

            return {
                guess: function () {
                    let char = '', cnt = 0
                    for (let i = 'a'.charCodeAt(0); i <= 'z'.charCodeAt(0); i++) {
                        let c = String.fromCharCode(i)
                        if (c in used) continue
                        let cur = 0
                        lst.forEach(x => cur += x.includes(c))
                        if (cur > cnt) cnt = cur, char = c
                    }

                    last_char = char
                    used[char] = 1
                    return char
                },
                response: function (result) {

                    if (last_result === result)
                        lst = lst.filter(x => !x.includes(last_char))
                    else ok[last_char] = 1

                    lst = lst.filter(x => {
                        for (let i = 0; i < word; i++) {
                            if (result[i] === '_') {
                                if (x[i] in ok) return false
                            } else if (result[i] !== x[i]) return false
                        }
                        return true
                    })

                    last_result = result
                }
            };
        }
    };
}