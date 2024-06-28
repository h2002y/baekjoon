const input = require("fs").readFileSync(process.platform === "linux" ? "/dev/stdin" : __dirname + "/input.txt").toString().trim().split("\n").map(BigInt);
const [A, B] = input;
console.log((A + B).toString());