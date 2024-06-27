const input = require("fs").readFileSync(process.platform === "linux" ? "/dev/stdin" : __dirname + "/input.txt").toString().split("\n").map(Number);
const [A, B, C] = input;
console.log(A + B - C);
console.log(parseInt(A.toString() + B.toString()) - C);