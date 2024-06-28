const input = require("fs").readFileSync(process.platform === "linux" ? "/dev/stdin" : __dirname + "/input.txt").toString().split(" ").map(Number);
const [n1, n2, n12] = input;
const N = parseInt((n1 + 1) * (n2 + 1) / (n12 + 1)) - 1;
console.log(N);