const input = require("fs").readFileSync(process.platform === "linux" ? "/dev/stdin" : __dirname + "/input.txt").toString().split("\n").map(BigInt);
const [A, B, C] = input;
console.log(((B - C) / A).toString());