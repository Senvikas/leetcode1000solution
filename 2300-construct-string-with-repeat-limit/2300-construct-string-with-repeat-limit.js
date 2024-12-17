var repeatLimitedString = function(s, repeatLimit) {
    const freq = Array(26).fill(0);
    for (const ch of s) {
        freq[ch.charCodeAt(0) - 'a'.charCodeAt(0)]++;
    }

    const pq = [];
    for (let i = 25; i >= 0; i--) {
        if (freq[i] > 0) {
            pq.push([String.fromCharCode('a'.charCodeAt(0) + i), freq[i]]);
        }
    }
    pq.sort((a, b) => b[0].charCodeAt(0) - a[0].charCodeAt(0));

    let ans = "";
    while (pq.length > 0) {
        let [ch1, cnt1] = pq.shift();
        let addCount = Math.min(repeatLimit, cnt1);
        ans += ch1.repeat(addCount);
        cnt1 -= addCount;

        if (cnt1 > 0 && pq.length > 0) {
            let [ch2, cnt2] = pq.shift();
            ans += ch2;
            cnt2--;

            pq.push([ch1, cnt1]);
            if (cnt2 > 0) {
                pq.push([ch2, cnt2]);
            }
            pq.sort((a, b) => b[0].charCodeAt(0) - a[0].charCodeAt(0));
        }
    }

    return ans;
};
