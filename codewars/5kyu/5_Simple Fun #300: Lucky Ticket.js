function luckyTicket(s) {
    let cnt = {}, cnt2 = {}, r = s.length
    for (let i = 0; i < 26; i++) cnt[i] = cnt2[i] = 0
    for (let i = 0; i < s.length; i++) {
        cnt[s[i].charCodeAt() - 97]++;
    }

    for (let i = 0; i < s.length; i++) {
        cnt2[s[i].charCodeAt() - 97]++;
        cnt[s[i].charCodeAt() - 97]--;
        let t = 0;
        for (let j = 0; j < 26; j++) {
            if (cnt[j] < cnt2[j]) t += cnt2[j] - cnt[j]
            else t += cnt[j] - cnt2[j]
        }
        r = Math.min(r, t)
    }

    return r
}