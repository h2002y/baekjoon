const input = require("fs").readFileSync(process.platform === "linux" ? "/dev/stdin" : __dirname + "/input.txt").toString().trim().split("\n");
const vowels = new Set(['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']);

input.slice(0, -1).forEach(sentance => {
    let cnt = 0;
    Array.from(sentance).forEach(word => {
        if (vowels.has(word)) cnt++;
    });
    console.log(cnt);
});